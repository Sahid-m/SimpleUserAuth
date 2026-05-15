# SimpleUserAuth

SimpleUserAuth is a small C++ console application that demonstrates a basic username and password flow. It lets a user register, log in, and recover a stored password from a local text file.

> This project is intended for learning and practice. It stores credentials in plain text and should not be used for real user accounts without adding password hashing, input validation, and safer storage.

## Features

- Register a new user with a username and password.
- Log in by matching credentials against `registry.txt`.
- Recover a password by searching for a username.
- Store sample user records in a simple space-separated text file.

## Project Files

| File | Purpose |
| --- | --- |
| `LoginSys.c++` | Main C++ source file for the console authentication menu. |
| `registry.txt` | Local credential store used by the demo program. |
| `LoginSys.exe` | Prebuilt Windows executable included in the repository. |
| `README.md` | Project setup, usage, and security notes. |

## Requirements

- Windows Command Prompt or PowerShell for the included executable.
- A C++ compiler such as MinGW g++ or Microsoft Visual C++ if you want to rebuild from source.

The program calls `cls` and `Pause`, which are Windows console commands. On Linux or macOS, replace those calls or run the program in a compatible Windows environment.

## Build From Source

Using MinGW g++:

```bash
g++ LoginSys.c++ -o LoginSys.exe
```

Using Microsoft Visual C++ Developer Command Prompt:

```bat
cl /EHsc LoginSys.c++ /Fe:LoginSys.exe
```

## Run

From the project folder:

```bat
LoginSys.exe
```

Or, after building with g++:

```bash
./LoginSys.exe
```

## Menu Options

When the program starts, choose one of these actions:

1. Register a new user.
2. Log in as an existing user.
3. Find a forgotten password by username.
4. Close the application.

## Registry File Format

User records are stored in `registry.txt` as one username and one password per line:

```text
username password
```

Example:

```text
alice alice123
bob bob123
```

Because the parser reads values separated by whitespace, usernames and passwords should not contain spaces.

## Example Workflow

1. Start the program.
2. Select `1` to register a new user.
3. Enter a username and password.
4. Return to the menu and select `2`.
5. Enter the same username and password to confirm login succeeds.

## Security Notes

This demo intentionally keeps the implementation simple. Before adapting it for real applications, address these limitations:

- Passwords are stored in plain text.
- The forgot-password flow prints the stored password directly.
- Input is not sanitized or length-limited.
- Duplicate usernames are not prevented.
- Credentials are stored in a local file without access-control checks.

For production-style authentication, hash passwords with a modern password hashing algorithm, avoid password recovery by disclosure, validate input carefully, and store user records in a protected database or secrets-aware storage layer.

## Troubleshooting

- If the executable does not start, rebuild it with a local C++ compiler.
- If login always fails, make sure `registry.txt` is in the same folder as the executable.
- If the screen-clearing or pause commands fail, run the program from Windows Command Prompt or PowerShell.
- If your compiler warns about calls to `main()`, the warning comes from the current demo control flow. The program may still build, but a future cleanup should replace those calls with a loop around the menu.
