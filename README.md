# SimpleUserAuth

SimpleUserAuth is a small Windows console application written in C++ that demonstrates basic user authentication flows:

- register a new user
- log in with an existing account
- recover a password by username

The app stores credentials in a local text file named `registry.txt`.

## Files

- `LoginSys.c++` - source code for the console app
- `LoginSys.exe` - prebuilt Windows executable
- `registry.txt` - sample credential store used by the program

## Requirements

- Windows
- A C++ compiler such as `g++`

## Build

From the project directory, compile the source file with:

```bash
g++ LoginSys.c++ -o LoginSys.exe
```

## Run

Run the executable from File Explorer or the terminal:

```bash
LoginSys.exe
```

## How it works

1. Choose an action from the menu.
2. Register a user to append credentials to `registry.txt`.
3. Log in with a stored username and password.
4. Use the forgot-password option to search the file by username.

## Notes

- This is a learning project, so passwords are stored in plain text.
- The program uses `system("cls")` and `system("Pause")`, so it is intended for Windows.
- `registry.txt` must stay in the same folder as the executable.
