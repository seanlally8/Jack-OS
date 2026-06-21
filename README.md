# Jack-OS

The operating system is complete for the purposes of this course. Still remaining is the global task of ensuring my VMTranslator does not bloat the code at the bottom level. It appears this can be accomplished by factoring out the call-related code to a single function that gets tied into the bootstrap code. So whenever the VMTranslator hits call function 1, it will jump the assembly code to the call-function loop. This should help decrease the result by thousands of lines of code.
