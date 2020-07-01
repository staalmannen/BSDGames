</$objtype/mkfile

#only include those that successfully build
# will never work: dab (c++)

DIRS=lib adventure arithmetic battlestar bcd\
	caesar countmail cribbage fish morse number\
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

