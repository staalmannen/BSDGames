</$objtype/mkfile

#only include those that successfully build

DIRS=lib adventure arithmetic caesar fish\
	wargames worm worms wtf



all:V:
	for (i in $DIRS)
		@{ cd $i; mk }

install:V:
	for (i in $DIRS)
		@{ cd $i; mk $target }

clean:V:
	for (i in $DIRS)
		@{ cd $i; mk $target }

nuke:V:
	for (i in $DIRS)
		@{ cd $i; mk $target }

