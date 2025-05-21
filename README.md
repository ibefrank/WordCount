# AVL Word Counter

This project implements a word counting application using an AVL tree. The AVL tree is a self-balancing binary search tree that ensures efficient insertion, deletion, and search operations. The project is designed to read a text file, count the frequency of each word, and display the results in sorted order.

## Features

- **AVL Tree Implementation**: A generic AVL tree is implemented to store and manage word data.
- **Word Frequency Counting**: Counts the occurrences of each word in a given text file.
- **Case Insensitivity**: Words are converted to lowercase to ensure case-insensitive counting.
- **Sorted Output**: Words are displayed in alphabetical order along with their frequencies.

## File Structure

- **`WordCount.h` and `WordCount.cpp`**: Contains the `WordCount` class, which handles file reading and word insertion into the AVL tree.
- **`AVLTree.h` and `AVLTree.cpp`**: Implements the generic AVL tree and its associated operations.
- **`BinaryTree.h`**: A base class for tree structures (if applicable).
   
## Dependencies

- C++ Standard Library
- Visual Studio 2022 IDE (for building and running the project)

## Classes and Methods

### `WordCount`
- **`readFile(const std::string& filename)`**: Reads a file and inserts words into the AVL tree.
- **`printWordCounts()`**: Prints the word frequencies in sorted order.

### `WordTree` (Derived from `AVLTree`)
- **`insert(const std::string& word)`**: Inserts a word into the AVL tree.
- **`printTree()`**: Prints the tree in sorted order.

### `AVLTree`
- **`insert(const T& x)`**: Inserts an element into the AVL tree.
- **`remove(const T& x)`**: Removes an element from the AVL tree.
- **`printTree()`**: Prints the tree in sorted order.

## Contributing

Feel free to fork the repository and submit pull requests for improvements or bug fixes.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
