# E89 Pedagogical & Technical Lab
# project:     rev
# created on:  2022-11-28 - 11:34 +0100
# 1st author:  victor.vandeputte - victor.vandeputte
# description: Makefile


NAME		=	libvector

ARCH_NAME	=	$(NAME).a

SRCS		=	$(shell find src/ -name "*.c")

OBJS		=	$(SRCS:.c=.o)

NAME_TEST	=	test.out

SRCS_TEST	=	$(shell find test/ -name "*.c")

OBJS_TEST	=	$(SRCS_TEST:.c=.o)

IFLAGS		=	-Iinclude/

CFLAGS		+=	-W -Wall -Wextra $(IFLAGS)

LDFLAGS		+=

CC		:=	gcc

ARRC		:=	ar rc

RM		=	rm -vf

RMM		=	rm -f

ifdef RELEASE
CFLAGS += -O2
endif

ifdef DEBUG
CFLAGS += -g
endif

%.o: %.c
	@printf	"[\033[0;36mCompilation\033[0m]% 35s\r" $<  | tr " " "."
	@$(CC) -c -o $@ $< $(CFLAGS)
	@printf "[\033[0;32mCompilé\033[0m]% 40s\n" $< | tr " " "."

all:	$(ARCH_NAME)

debug:	CFLAGS	+= -g
debug:	$(NAME)

test:	$(NAME_TEST)

archive: $(ARCH_NAME)

$(NAME): $(OBJS)
	@printf "\033[5;36mObjets Compilés avec Succès!\033[0m\n"
	$(CC) $(LDFLAGS) $(CFLAGS) $(OBJS) -o $(NAME)
	@printf "\033[6;32mCompilation Terminée\033[0m\n"

$(ARCH_NAME):$(OBJS)
	@printf "\033[5;36mObjets Compilés avec Succès!\033[0m\n"
	$(ARRC) $(ARCH_NAME) $(OBJS)
	@printf "\033[6;36mArchive crée avec Succès!\033[0m\n"

$(NAME_TEST):$(OBJS) $(OBJS_TEST)
	@printf "\033[5;36mObjets Compilés avec Succès!\033[0m\n"
	$(CC) -o $(NAME_TEST) $(OBJS_TEST) $(OBJS) -lcriterion
	@printf "\033[6;32mTests Compilés avec Succès!\033[0m\n"

exe:
	make archive
	make $(NAME_TEST)
	./$(NAME_TEST)
	make fclean

clear:
	@printf "[\033[31mSuppression\033[m][Déchets]% 48s\n" `$(RM) */*~ *~ */*#* *#* *.o | wc -l | tr -d "'"` | tr " " "."

clean:
	@printf "[\033[31mSuppression\033[m][OBJS]% 51s\n" `$(RM) $(OBJS) | wc -l | tr -d "'"` | tr " " "."
	@printf "[\033[31mSuppression\033[m][OBJS_TEST]% 46s\n" `$(RM) $(OBJS_TEST) | wc -l | tr -d "'"` | tr " " "."

fclean: clean clear
	@printf "[\033[31mSuppression\033[m][Exe]% 52s\n" `$(RMM) $(NAME)` '$(NAME)' | tr " " "."
	@printf "[\033[31mSuppression\033[m][Tests]% 50s\n" `$(RMM) $(NAME_TEST)` '$(NAME_TEST)' | tr " " "."
	@printf "[\033[31mSuppression\033[m][Archive]% 48s\n" `$(RMM) $(ARCH_NAME) $(ARCH_NAME2)` '$(ARCH_NAME)' | tr " " "."

mclean: clean clear
	@printf "[\033[31mSuppression\033[m][Exe]% 52s\n" `$(RMM) $(NAME)` '$(NAME)' | tr " " "."
	@printf "[\033[31mSuppression\033[m][Archive]% 48s\n" `$(RMM) $(ARCH_NAME) $(ARCH_NAME2)` '$(ARCH_NAME)' | tr " " "."

re:	fclean
	make -j4 all

.PHONY: all clean fclean re
