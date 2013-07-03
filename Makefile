DIR_SERVER  =	serveur/

DIR_CLIENT  =	client/

DIR_GUI	    =	gui/

all:
		@(cd $(DIR_GUI) && $(MAKE))

clean:
		@(cd $(DIR_GUI) && $(MAKE) $@)

fclean:		clean
		@(cd $(DIR_GUI) && $(MAKE) $@)

re:		fclean all
