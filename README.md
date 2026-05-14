# SimpleUserAuth

SimpleUserAuth is a small C++ console app for registering users, logging in, and recovering a password from a local text file.

## What it does

- Register a new username and password
- Log in with existing credentials
- Recover a password by username
- Store accounts in `registry.txt`

## Files

- `LoginSys.c++` - main program source
- `registry.txt` - local credential store
- `LoginSys.exe` - prebuilt Windows binary

## Requirements

- A C++ compiler such as `g++`
- A terminal or command prompt
- Windows for the included executable and console commands

## Build

Use any C++ compiler that can build a single translation unit.

```bash
g++ LoginSys.c++ -o SimpleUserAuth
```

On Windows, you can also build:

```bash
g++ LoginSys.c++ -o SimpleUserAuth.exe
```

## Run

Run the binary from the repository root so it can find `registry.txt`:

```bash
./SimpleUserAuth
```

On Windows:

```bash
SimpleUserAuth.exe
```

## Menu

When the app starts, choose one of these actions:

1. Register a new user
2. Log in as an existing user
3. Recover a forgotten password
4. Exit

## Example workflow

Register a user, then log in with the same credentials:

```text
Enter Your Actions : 1
Please Enter Your Username : alice
Please Enter Your Password : alice123
Registration Succesful

Enter Your Actions : 2
Please Enter Your Username : alice
Please Enter Your Password : alice123
Login Successful
```

## Registry format

Each line in `registry.txt` stores one record:

```text
username password
```

Example:

```text
alice alice123
bob bob123
```

The current program reads the file as plain text and does not support spaces inside usernames or passwords.

## Security notes

This project is for learning only.

- Passwords are stored in plain text
- Duplicate usernames are allowed
- Input validation is minimal
- Password recovery prints the saved password directly
- The program depends on local file storage only
- The source uses Windows console commands such as `cls` and `Pause`

## Troubleshooting

- If the app says it cannot find a user, make sure you are running it from the repository root so it can read `registry.txt`.
- If you build on Linux or macOS, the `system("cls")` and `system("Pause")` calls are Windows-specific and may not behave the same way.
- If you want to reset the app, edit or clear `registry.txt`.

## Notes

- `LoginSys.c++` is recursive in a few places, so the menu returns to `main()` after each action.
- The app is intentionally simple and does not use a database or hashing.
