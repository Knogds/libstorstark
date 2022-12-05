
Connect your STM32F4-discovery via USB.


Build everything - library (in libstorstark) and projects:

    stay in the current directory:

        Use:

            make

        to run 'make' on all subfolders.

            make clean

        to run 'make clean' on all subfolders.

Start your own project:

    cd projects
        
        cp -av blink yourproject
        cd yourproject
        mv blink.c yourproject.c
        edit the Makefile:
            'NAME = blink' -> 'NAME = yourproject'
            (be careful *not* 'NAME = yourproject ' - space on the end on line)

Upload to board:

    make && make upload

