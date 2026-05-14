# SimpleUserAuth

SimpleUserAuth is a small C++ console application that demonstrates a
file-backed username and password workflow. It lets a user register, log in,
and recover a stored password from a local `registry.txt` file.

This project is intentionally simple and is useful for learning basic C++
functions, file I/O, menu-driven console programs, and credential lookup logic.

## Features

- Register a new username and password.
- Save credentials to `registry.txt`.
- Log in by checking the entered credentials against the saved registry.
- Look up a password by username through the "Forgot Password" menu.
- Run as a single-file C++ console program.

## Repository Files

| File | Purpose |
| --- | --- |
| `LoginSys.c++` | Main source file containing the menu and authentication logic. |
| `registry.txt` | Local text file used to store usernames and passwords. |
| `LoginSys.exe` | Prebuilt Windows executable included in the repository. |
| `README.md` | Project documentation. |

## Requirements

- A C++ compiler such as `g++`, MinGW, or MSVC.
- Windows is the easiest environment because the program uses `system("cls")`
  and `system("Pause")`.

The source can also compile on Linux or macOS, but those Windows-specific
console commands may need to be replaced before running.

## Build

Using `g++`:

```bash
g++ LoginSys.c++ -o SimpleUserAuth
```

Using MinGW on Windows:

```bash
g++ LoginSys.c++ -o SimpleUserAuth.exe
```

## Run

On Windows:

```bash
SimpleUserAuth.exe
```

If you built the program yourself:

```bash
./SimpleUserAuth
```

The program shows this menu:

```text
1. Register a New User
2. Login as an existing user
3. Forgot Password
4. Close the applications
```

## Usage

1. Select `1` to register a new account.
2. Enter a username and password.
3. The program appends the credentials to `registry.txt`.
4. Select `2` to log in with the same username and password.
5. Select `3` if you want to recover a password by username.

## Registry Format

Credentials are stored in plain text, one account per line:

```text
username password
```

Example:

```text
alice hunter2
bob password123
```

The program reads the file with the stream extraction operator (`>>`), so
usernames and passwords should not contain spaces.

## Security Notes

This project is for learning only. It is not suitable for production use.

Important limitations:

- Passwords are stored in plain text.
- There is no password hashing or salting.
- The forgot-password flow prints the saved password.
- There is no duplicate username check.
- Input validation is minimal.
- Recursively calling `main()` is not a recommended application structure.

For a real authentication system, use password hashing, a proper database,
secure reset tokens, and a tested authentication framework.

## Troubleshooting

`registry.txt` is not found:

Create an empty file named `registry.txt` in the same directory where the
program runs.

Console commands fail on Linux or macOS:

Replace `system("cls")` and `system("Pause")` with portable alternatives.

Login always fails:

Check that `registry.txt` is in the current working directory and that each
line contains exactly one username and one password separated by whitespace.

## Possible Improvements

- Hash passwords before storing them.
- Prevent duplicate usernames.
- Replace recursive menu calls with a loop.
- Add input validation and error handling.
- Store credentials in a structured format such as JSON or SQLite.
- Add unit tests for registration, login, and password recovery behavior.
