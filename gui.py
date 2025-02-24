from kivy.app import App
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.textinput import TextInput
from kivy.uix.button import Button
from kivy.uix.label import Label
from kivy.uix.scrollview import ScrollView
from kivy.uix.gridlayout import GridLayout


class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end_of_word = False
        self.frequency = 0


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word, frequency=0):
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.is_end_of_word = True
        node.frequency = frequency

    def search(self, prefix):
        node = self.root
        for char in prefix:
            if char not in node.children:
                return []
            node = node.children[char]
        return self._collect_words(node, prefix)

    def _collect_words(self, node, prefix):
        suggestions = []
        if node.is_end_of_word:
            suggestions.append((prefix, node.frequency))
        for char, child_node in node.children.items():
            suggestions.extend(self._collect_words(child_node, prefix + char))
        return sorted(suggestions, key=lambda x: -x[1])


class KeyboardApp(App):
    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        self.trie = Trie()
        self._load_sample_data()

    def _load_sample_data(self):
        # Add some sample words with frequencies
        self.trie.insert("hello", 10)
        self.trie.insert("help", 8)
        self.trie.insert("happy", 9)
        self.trie.insert("happiness", 7)
        self.trie.insert("heart", 6)
        self.trie.insert("heat", 5)
        self.trie.insert("hero", 4)

    def build(self):
        self.root_layout = BoxLayout(orientation="vertical", padding=10, spacing=10)

        # Input area
        self.text_input = TextInput(hint_text="Type here...", font_size=20, size_hint_y=0.2, multiline=False)
        self.text_input.bind(text=self.update_suggestions)
        self.root_layout.add_widget(self.text_input)

        # Suggestions area
        self.suggestion_box = GridLayout(cols=4, size_hint_y=0.2)
        self.root_layout.add_widget(self.suggestion_box)

        # Emoji picker
        emoji_layout = BoxLayout(size_hint_y=0.2)
        emojis = ["😊", "😂", "❤️", "👍", "😭", "🎉", "🔥", "🙏"]
        for emoji in emojis:
            btn = Button(text=emoji, font_size=25, on_press=self.add_emoji_to_input)
            emoji_layout.add_widget(btn)
        self.root_layout.add_widget(emoji_layout)

        # Keyboard buttons
        keyboard_layout = GridLayout(cols=10, size_hint_y=0.4)
        for char in "abcdefghijklmnopqrstuvwxyz":
            btn = Button(text=char, font_size=20, on_press=self.add_char_to_input)
            keyboard_layout.add_widget(btn)
        keyboard_layout.add_widget(Button(text="Space", font_size=20, on_press=self.add_space_to_input))
        keyboard_layout.add_widget(Button(text="Backspace", font_size=20, on_press=self.remove_last_char))
        self.root_layout.add_widget(keyboard_layout)

        return self.root_layout

    def update_suggestions(self, instance, value):
        self.suggestion_box.clear_widgets()
        if value.strip():
            prefix = value.split()[-1]  # Get the last word
            suggestions = self.trie.search(prefix)
            for word, _ in suggestions[:8]:  # Display top 8 suggestions
                btn = Button(text=word, size_hint_y=None, height=40, on_press=self.add_suggestion_to_input)
                self.suggestion_box.add_widget(btn)

    def add_suggestion_to_input(self, instance):
        currentent_text = self.text_input.text.split()
        currentent_text[-1] = instance.text  # Replace last word with suggestion
        self.text_input.text = " ".join(currentent_text) + " "

    def add_char_to_input(self, instance):
        self.text_input.text += instance.text

    def add_space_to_input(self, instance):
        self.text_input.text += " "

    def remove_last_char(self, instance):
        self.text_input.text = self.text_input.text[:-1]

    def add_emoji_to_input(self, instance):
        self.text_input.text += instance.text


if __name__ == "__main__":
    KeyboardApp().run()
