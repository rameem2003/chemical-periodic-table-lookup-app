# Chemical Periodic Table Lookup App

**Software Version:** 1.0 Stable  
**Programming Language:** C

## Overview

The **Chemical Periodic Table Lookup App** is a console-based application designed to provide detailed information about chemical elements based on either their atomic number or atomic symbol. The application includes the following features:

- Fast lookup of chemical element details.
- A comprehensive database of 118 chemical elements.
- Clean console output with formatting for better readability.
- Simulation of loading time for an enhanced user experience.

---

## Features

### 1. Lookup by Atomic Number

Users can input the atomic number of a chemical element, and the application will display:

- Element name
- Atomic symbol
- Atomic number
- Atomic mass
- Electronic configuration

### 2. Lookup by Atomic Symbol

Users can input the atomic symbol of a chemical element, and the application will retrieve and display the same detailed information.

---

## Data Structure

The app uses a `struct` called `Element` to store information about each chemical element. The structure contains:

- **`atomicNumber`** (int): Atomic number of the element.
- **`atomicSymbol`** (char[50]): Atomic symbol of the element.
- **`atomName`** (char[20]): Full name of the element.
- **`atomicMass`** (double): Atomic mass of the element.
- **`electronic_configuration`** (char[50]): Electronic configuration of the element.

Example:

```c
struct Element {
    int atomicNumber;
    char atomicSymbol[50];
    char atomName[20];
    double atomicMass;
    char electronic_configuration[50];
};
```

---

## Usage

### Main Menu

Upon starting the application, users are presented with the following options:

1. Search by atomic number.
2. Search by atomic symbol.
3. Exit the program.

### Input Validation

- The app checks if the provided atomic number or atomic symbol exists in the database.
- If not found, an error message is displayed.

### Example Output

For an atomic number search:

```text
############################################################
## Atom Name: Oxygen
## Atomic Symbol: O
## Atomic Number: 8
## Atomic Mass: 15.999000
## Electronic Configuration: 1s2 2s2 2p4
############################################################
```

---

## Functions

### 1. `displayAtoms`

Displays the details of a specific element in a formatted manner.

#### Parameters

- `element` (struct Element): The element to display.

#### Example

```c
void displayAtoms(struct Element element) {
    printf("Atom Name: %s\n", element.atomName);
    // Additional output lines
}
```

### 2. `displayAtomBySearchingAtomicNumber`

Searches for an element using its atomic number.

#### Parameters

- `userAtomicNumber` (int): The atomic number entered by the user.
- `elements` (struct Element[]): The database of elements.

### 3. `displayAtomBySearchingAtomicSymbol`

Searches for an element using its atomic symbol.

#### Parameters

- `userAtomicSymbol` (char[]): The atomic symbol entered by the user.
- `elements` (struct Element[]): The database of elements.

### 4. `startApp`

Displays the main menu and handles user input.

---

## Dependencies

- **Standard Input/Output Library** (`<stdio.h>`): Used for console input and output.
- **String Library** (`<string.h>`): Used for string comparison.
- **Windows.h**: Used for simulating delays with `Sleep` function.

---

## Limitations

- Currently supports only English for console output.
- Not designed for multi-platform compatibility (uses `windows.h` for `Sleep`, which may not work on non-Windows systems).

---

## Future Improvements

- Add support for other platforms (replace `Sleep` with a cross-platform alternative).
- Include more user-friendly error messages.
- Allow searching by partial atomic symbol or name.
- Add a graphical user interface (GUI).

---
