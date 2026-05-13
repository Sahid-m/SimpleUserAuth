# SimpleUserAuth

SimpleUserAuth is a small console-based C++ user authentication system. It lets users register, log in, and recover a forgotten password from a local text-file registry.

## Features

- Register a new user with a username and password
- Log in with existing credentials
- Recover a password by username
- Store user records in `registry.txt`
- Simple menu-driven command-line interface

## Project Structure

- `LoginSys.c++` - main C++ source file
- `registry.txt` - local credential registry used by the program
- `LoginSys.exe` - prebuilt Windows executable

## Requirements

- A C++ compiler such as `g++`
- Windows command prompt for the existing `system("cls")` and `system("Pause")` calls

On Linux or macOS, the source can still be compiled, but the Windows-specific console commands may print shell warnings unless they are adapted.

## Build

Compile the source file with `g++`:

    g++ LoginSys.c++ -o LoginSys

On Windows, you can build an executable with:

    g++ LoginSys.c++ -o LoginSys.exe

## Run

After building, run the application from the project directory:

    ./LoginSys

On Windows:

    LoginSys.exe

The application reads and writes `registry.txt` in the current working directory, so run it from the repository root if you want to use the included registry file.

## Usage

When the program starts, choose one of the menu options:

1. Register a new user
2. Log in as an existing user
3. Recover a forgotten password
4. Close the application

### Register

Select option `1`, then enter a username and password. The credentials are appended to `registry.txt`.

### Log In

Select option `2`, then enter a username and password. The program checks the credentials against `registry.txt`.

### Forgot Password

Select option `3`, then enter a username. If the username exists in `registry.txt`, the saved password is displayed.

## Data Format

Each line in `registry.txt` stores one user record in this format:

    username password

Example:

    alice alice123
    bob bob123

## Security Notes

This project is intended for learning and demonstration only. It is not production-ready because:

- Passwords are stored in plain text
- Duplicate usernames are not prevented
- Input validation is minimal
- Password recovery displays the saved password directly
- The registry file is stored locally without encryption

For a production authentication system, use password hashing, salted credentials, secure storage, validation, and a proper database.

## Contributing

Contributions are welcome. Suggested improvements include:

- Hash passwords before storing them
- Prevent duplicate usernames
- Add input validation
- Replace recursive `main()` calls with a loop
- Improve cross-platform console handling
- Add automated tests

## License

No license file is currently included in this repository.
