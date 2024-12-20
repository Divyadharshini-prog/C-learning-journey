# C-learning-journey

## This repo is created for learning C

This is a personal learning project for me which includes basic programs to some of the development using **PIC Microcontroller**.  
The basic C programs include working with numbers, strings, recursion, arithmetic operations, swapping, etc.

**PIC microcontrollers** typically have a small amount of on-chip RAM and flash memory, which can be expanded using external memory devices. They also feature a wide range of peripherals, including timers, analog-to-digital converters, and communication interfaces such as **UART**, **SPI**, and **I2C**.

### The code using PIC Microcontroller (PIC16F877A) includes:
1. Basic LED operation  
2. Pullup and pulldown  
3. LCD 16x2  
4. PWM  
5. ADC  
6. Keypad interface  
7. Seven-segment Display  
8. UART  
9. I2C  

---

### Steps to use git and github
#### Create a Personal Access Token in Git

- Sign in to GitHub.
- Click on your profile picture in the upper right corner, then click on Settings.
- In the left sidebar, click on Developer settings.
- Click on Personal access tokens and then Tokens (classic).
- Click on Generate new token.
- Add a note for your token (e.g., "Git operations").
- Select the scopes (permissions) you want to grant this token. For basic Git operations, you can select:
- repo (for full control of private repositories)
- Click on Generate token.
- Copy the token immediately. You won't be able to see it again.
- Use the Personal Access Token
- When you perform Git operations that require authentication (like cloning, pushing, or pulling), use your PAT instead of your GitHub password.

#### Steps for starting with Git
1. Clone the Repository Locally
Copy the Repository URL:
On the repository page, click the Code button.
Copy the URL provided under Clone with HTTPS or Clone with SSH (depending on your authentication method).

2. Open Your Terminal:
Navigate to the directory where you want to store the repository.
Use the following command to clone the repository (replace the URL with your copied URL):
```
git clone https://github.com/your_username/test-repo.git
```
Or, if using SSH:
```
git clone git@github.com:your_username/test-repo.git
```

3. Navigate to the Repository Folder:
```
cd test-repo
```
4. Add Files and Make Changes
Create a New File: You can create a new file in your test repository. For example, create a simple text file:

echo "This is a test file." > test-file.txt

5. Check the Status: See the status of your repository to check which files are changed or untracked:
```
git status
```
6.Add the File to Staging: Stage the new file for commit:
```
git add test-file.txt
```
7. Commit Your Changes: Commit your changes with a descriptive message:
```
git commit -m "Add test file"
```
8. Push Changes to GitHub
Push Your Changes: Push the committed changes to your GitHub repository:
```
git push origin main
```
(Replace main with master if your default branch is named that.)
If the above one is not working or showing some error try this command 
```
git push -u origin main
```
(Replace main with master if your default branch is named that.)
Explore Your Repository on GitHub
Go back to your GitHub repository page, and you should see the test-file.txt listed there.
You can now continue to experiment with various Git commands, such as creating branches, merging, or exploring more features of GitHub.

### Steps to run the code in VS Code:
1. Save the code in the desired location of your git repository.  
2. Then run these commands:  

```
gcc float_to_round.c -o float_to_round.exe             # This command creates an .exe file in the directory
.\float_to_round.exe                                   # This command executes the .exe file
```

## Useful Links
- [GitHub Homepage](https://github.com)
- [C Programming Basics](https://en.wikipedia.org/wiki/C_(programming_language))
- [gdb commands in windows and linux](http://www.yolinux.com/TUTORIALS/GDB-Commands.html)
- [Contact Me](dharshiniperiyar277@gmail.com)



