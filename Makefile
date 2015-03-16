NAME	= pfdf

CC	= g++

RM	= rm -f

SRCDIR	= src/

INCDIR	= inc/

OBJDIR	= obj/

LIBDIR 	= lib/

LIBNAME = libNoise.a

SRCS	= main.cpp \
	  fdf.cpp \
	  Settings.cpp

OBJS	= $(addprefix $(OBJDIR), $(SRCS:.cpp=.o))

INCCOMP	= -I$(INCDIR) -I$(LIBDIR)

CXXFLAGS = -O2 -march=native -std=c++1y

LDFLAGS	= -lsfml-graphics -lsfml-window -lsfml-system -L$(LIBDIR) -lNoise

dummy	:= 	$(shell test -d $(OBJDIR) || mkdir $(OBJDIR)) \
		$(shell test -d $(LIBDIR) || mkdir $(LIBDIR))

$(OBJDIR)%.o:	$(SRCDIR)%.cpp
	$(CC) $(CXXFLAGS) $(INCCOMP) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)  $(LDFLAGS) $(LIB)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
