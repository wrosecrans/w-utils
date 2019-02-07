# w-utils  (DRAFT)

The Worst implementations of some userland utilities

This software will probably be released under the Apache 2 license, pending review.

# Userland?

The Kernel is all the scary bits of an OS that talk directly to the hardware, and do Serious Business.  People pay attention to big useful Applications on a desktop computer like a GUI word processor or a fancy 3D modelling program.  On a server system, web server software like Apache or Nginx on a server get all of the attention.  But the bits in the middle that are so important seem to get forgotten.

All of the little commands like 'ls' and 'cp' are completely necessary for you do do important work to get to your big important Applications that you use all day, and collectively they are called the userland.

# UNIX style CLI Utilities, a brief history

Being a very boring sort of person, I decided to do my own implementation of some traditional UNIX utilities to get a better appreciation of how they work.  Historically, the earliest implementations were mainly written in assembly:  https://github.com/jserv/unix-v1/tree/master/src/cmd

By the 1980's, UNIX had grown up and spread out to many different architectures and kinds of hardware so the utilities were largely implemented in portable C, for example in BSD 2.9 from 1983 at the Unix Heritage Society:  https://minnie.tuhs.org/cgi-bin/utree.pl?file=2.9BSD/usr/src/cmd/ls

In the 1990's, Linux invigorated a push for new GPL versions of the userland utilities that were unshackled from the then-dominant commercial UNIX vendors.  Higher level and more modern languages like C++ were becoming popular.  Exciting development projects like NeXT, BeOS, and Taligent were pushing modern language features into new Operating Systems.  The Taligent API's seemed especially keep to show off the fact that modern computers could (and should!) display more than 80 columns of text with things like TaligentTypeExtensionTemplateDeclarationsMacro_Abstract    (No, but seriously.  That name isn't even a joke.  Here's some Taligent sample code:  https://root.cern.ch/TaligentDocs/TaligentOnline/DocumentRoot/1.0/Docs/samples/Supported/Enablers/AtomicModel/AtomicModel.h from https://root.cern.ch/TaligentDocs/TaligentOnline/DocumentRoot/1.0/Docs/index.html )  BeOS encouraged people to migrate past the traditional Posix API's not just for things like UI and Windowing, but also for basic file manipulation using the BFile class instead of posix open() and close() https://www.haiku-os.org/legacy-docs/programming_the_be_operating_system.pdf (see p. 360 for the section on files.)  Similarly, NeXT was pushing for adoption of a class library based on NSObject using Objective C.

So in that time of excitement and revolution during the 1990's, GNU implemented their coreutils for Linux in C, because the honestly design of this stuff had mostly ossified in the 1980's.  None of those other 90's projects really went anywhere, so you can't blame them.  (Yes, The NS API's were used on OS-X, but they never became pervasive enough to displace the use of classic BSD userland utilities, using Posix and BSD API's under the hood.)

By the 2000's, things were really changing.  The classic commercial UNIX vendors of the 1980's were long gone.  C was starting to seem archaic, and now we were supposed to write everything in JavaScript if we wanted to look cool.  GNU coreutils certainly saw activity during the 21st Century -- Bugs were fixed, and features were added.  But the basic design hadn't changed much -- There are still parts of coreutils that literally haven't changed since the 1990's because the design has been so stable:  https://github.com/coreutils/coreutils/blame/master/src/ls.c  Some of the small files haven't seen a single commit since "Star Trek: The Next Generation" was still in production.  The BSD ls has been about as stable as GNU's:  https://github.com/freebsd/freebsd/blame/master/bin/ls/ls.c with many lines not just being old enough to vote, but also old enough to rent a car.


# UNIX style CLI Utilities, from scratch

Anyhow, I decided to write some of my own.

I am using C++ as the main language.  It's considered low-level but portable, filling about the same niche that C filled in the 1980's.  Higher level languages like Python are certainly fast enough for many uses these days, and I am quite fond of Python.  But I would feel like I was cheating if I used a language that depended on a large and complicated interpreter or VM, so I am using a language that produces normal, native binaries that can be directly executed with no major dependencies.  (Except maybe a few shared libraries.)

# Building and running

Building depends on a modern C++ compiler, and CMake 3.5.  You'll need Boost, because std::filesystem from C++ 17 is still too hard to use on many systems despite the fact that I am writing this in 2019.

Building with CMake is straightforward, if you are lucky.

    mkdir build && cd build
    cmake ..
    cmake build .
    
    
If you are unlucky, you may wish to consult some CMake documentation: https://izzys.casa/2019/02/everything-you-never-wanted-to-know-about-cmake/  Or not.  Nothing makes you appreciate old-school Makefiles like reading CMake documentation.


I am very lazy, and these are simple proof-of-concept utilities.  I am making no effort to be fully compliant with all your favorite Posix or GNU command line flags.  The trade-off is that some modern C++ language features make parts of the code much shorter and easier to write.  (And thus, probably easier to read due to brevity.)  And, they do just enough to make for an interesting performance comparison with GNU and BSD utilities.

I have also adopted a simple mechanism for pluggable implementations to simplify benchmarking if you want to try something different.  Just add your function to the "methods" object in main() for cp or ls by adding

    methods["foo"] = name_of_my_function;
    
And it will automatically start appearing in the output of `ls --help` and be selectable with `ls --method foo`


