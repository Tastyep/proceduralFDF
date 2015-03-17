NAME	= pfdf

CC	= g++

RM	= rm -f

SRCDIR	= src/

INCDIR	= inc/

OBJDIR	= obj/

LIBFILES = libfiles/

LIBSDIR = lib/*/

SRCS	= main.cpp \
	  fdf.cpp \
	  Settings.cpp

OBJS	= $(addprefix $(OBJDIR), $(SRCS:.cpp=.o))

INCCOMP	= -I$(INCDIR) -I$(LIBFILES)

CXXFLAGS = -O2 -march=native -std=c++1y

LDFLAGS	= -lsfml-graphics -lsfml-window -lsfml-system -L$(LIBDIR) -lNoise

dummy	:= 	$(shell test -d $(OBJDIR) || mkdir $(OBJDIR)) \
		$(shell test -d $(LIBFILES) || mkdir $(LIBFILES))

$(OBJDIR)%.o:	$(SRCDIR)%.cpp
	$(CC) $(CXXFLAGS) $(INCCOMP) -o $@ -c $<

$(NAME):  libs $(OBJS)
	$(CC) -o $(NAME) $(OBJS)  $(LDFLAGS) $(LIBFILES)/*.a

libs:
	make -C $(LIBSDIR)
	cp -f $(LIBSDIR)/lib/* $(LIBFILES)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	make -C $(LIBSDIR) clean

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
