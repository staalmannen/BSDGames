</$objtype/mkfile
DIRS=lib caesar fish

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

