# Password Strength Checker - C

## Description
Password strength analyzer with detailed validation and user feedback system.

## Features
- **Length Validation**: minimum 8 characters.
- **Space Detection**: Identifies and flags spaces in passwords.
- **Character Type Validation**:
 - Lowercase letters (a-z)
 - Uppercase letters (A-Z)
 - Digits (0-9)
 - Special characters (!@#$%^&* etc.)
- **Scoring System**: 25 points per criteria (max 150 points)
- **User Feedback**: Specific improvement.
- **Memory Management**: Dynamic allocation with proper error handling.

## How to Compile
gcc password_checker.c -o password_checker

## How to Run
./password_checker

* Sample Output :

Enter Your Password: Test123
After reviewing: Test123
Fixes:
.Add Special characters

Enter Your Password: Test123!@#
After reviewing: Test123!@#
Your Password is Strong


* Technical Implementation:

- Language: C.
- Built from scratch without external libraries.
- Dynamic memory allocation with realloc optimization.
- Safe input handling with buffer overflow protection.
- Manual ASCII range validation for character classification.

* Security Considerations :

- No password storage.
- Buffer overflow protection.
- Clear feedback without revealing password patterns.

* What I Learned :

- Dynamic memory management in C.
- String manipulation and validation.
- ASCII value ranges for character classification.
- User input sanitization.
- Modular function design.

* Future Improvements :

- Add common password dictionary check.
- Create Python version with HIBP API integration.
- Add password generation feature.

# Author
[chaohm1] - August 2025
Part of SOC Analyst Portfolio.