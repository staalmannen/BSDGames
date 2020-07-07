</$objtype/mkfile

#dependencies: pdcurses, pcre

#only include those that successfully build
# Please note: I have only tested building, not that they work as intended
# will never work: dab (c++)
# boggle builds but depends on Pth and does not seem to work
# backgammon needs termcap.h - can it be hacked around?
# atc : several undefined things at linking
# hack needs termcap...


DIRS=lib adventure arithmetic battlestar banner bcd\
	caesar canfield countmail cribbage dm\
	factor fish fortune hangman morse number\
	pig pom ppt primes rain random\
	wargames worm worms wtf wump



all:V:
	for (i in $DIRS)
		@{ cd $i; mk }

install:V:
	for (i in $DIRS)
		@{ cd $i; mk $target }

clean:V:
	for (i in $DIRS)
		@{ cd $i; mk $target }
	cd lib: mk nuke

nuke:V:
	for (i in $DIRS)
		@{ cd $i; mk $target }

