# E89 Pedagogical & Technical Lab
# project:     bsh1
# created on:  2023-04-11 - 11:05 +0200
# 1st author:  noah.chantin - noah.chantin
# description: Makefile

NAME		=	bsh1

ARCH_NAME	=	lib$(NAME).a

ARCH_NAME2	=	libvector.a

SRCS		=	$(shell find src/ -name "*.c" ! -name "main.c")

OBJS		=	$(SRCS:.c=.o)

NAME_TEST	=	test.out

SRCS_TEST	=	$(shell find test/ -name "*.c")

OBJS_TEST	=	$(SRCS_TEST:.c=.o)

IFLAGS		=	-Iinclude/ -Ilib/include/

CFLAGS		+=	-W -Wall -Wextra $(IFLAGS)

LDFLAGS		+=

ARCHFLAGS	+=	$(ARCH_NAME) $(ARCH_NAME2)

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
	@printf	"[\033[0;36mCompilation\033[0m]% 57s\r" $<  | tr " " "."
	@$(CC) -c -o $@ $< $(CFLAGS)
	@printf "[\033[0;32mCompilé\033[0m]% 61s\n" $< | tr " " "."

all:	$(NAME)

debug:	CFLAGS	+= -g
debug:	$(NAME)

$(NAME):$(ARCH_NAME) $(OBJS)
	@printf "\033[0;36mObjets Compilés avec Succès!\033[0m\n"
	@$(CC) $(CFLAGS) src/main.c $(ARCHFLAGS) $(LDFLAGS) -o $(NAME)
	@printf "\033[1;32mCompilation Terminée\033[0m\n"

$(ARCH_NAME):$(OBJS) $(ARCH_NAME2)
	@printf "\033[0;36mObjets Compilés avec Succès!\033[0m\n"
	@$(ARRC) $(ARCH_NAME) $(OBJS)
	@printf "\033[1;32mArchive crée avec Succès!\033[0m\n"

$(ARCH_NAME2):
	@$(MAKE) -C lib
	@cp -v lib/libvector.a .

$(NAME_TEST):$(ARCH_NAME) $(OBJS_TEST)
	@printf "\033[0;36mObjets Compilés avec Succès!\033[0m\n"
	@$(CC) -o $(NAME_TEST) $(OBJS_TEST) $(ARCHFLAGS) -lcriterion
	@printf "\033[1;32mTests Compilés avec Succès!\033[0m\n"

exe: $(NAME_TEST)
	./$(NAME_TEST)

exa: $(NAME)
	./$(NAME)


Vsave: fclean
	@printf "\033[1;34m<Add files to git>\033[0m\n" `git add $(SRCS) $(SRCS_TEST) $(shell find include/ -name "*.h") $(shell find -name "*")`
	@printf "\033[1;34m<Comited added files>\033[0m\n"
	@git commit -m "$(NAME) Sauvegarde du `date '+%d/%m/%Y'` à `date '+%R'`"
	@printf "\033[1;34m<Push succesfully in branch main>\033[0m\n" `git push`

Nsave: fclean
	@printf "\033[1;34m<Add files to git>\033[0m\n" `git add $(SRCS) $(SRCS_TEST) $(shell find include/ -name "*.h") $(shell find -name "*")`
	@printf "\033[1;34m<Comited added files>\033[0m\n"
	@git commit -m "$(NAME) Sauvegarde du `date '+%d/%m/%Y'` à `date '+%R'`"
	@printf "\033[1;34m<Push succesfully in branch Noah>\033[0m\n" `git push --set-upstream origin Noah`

VVsave: fclean
	@printf "\033[1;34m<Add files to git>\033[0m\n" `git add $(SRCS) $(SRCS_TEST) $(shell find include/ -name "*.h") $(shell find -name "*")`
	@printf "\033[1;34m<Comited added files>\033[0m\n"
	@git commit -m "$(NAME) Sauvegarde du `date '+%d/%m/%Y'` à `date '+%R'`"
	@printf "\033[1;34m<Push succesfully in branch Victor>\033[0m\n" `git push --set-upstream origin Victor`

Msave: fclean
	@printf "\033[1;34m<Add files to git>\033[0m\n" `git add $(SRCS) $(SRCS_TEST) $(shell find include/ -name "*.h") $(shell find -name "*")`
	@printf "\033[1;34m<Comited added files>\033[0m\n"
	@git commit -m "$(NAME) Sauvegarde du `date '+%d/%m/%Y'` à `date '+%R'`"
	@printf "\033[1;34m<Push succesfully in branch Martin>\033[0m\n" `git push --set-upstream origin Martin`

mergeN:
	@printf "\033[1;34m<Go to main branch>\033[0m\n" `git checkout main`
	@printf "\033[1;34m<Pull main branch modif>\033[0m\n" `git pull`
	@printf "\033[1;34m<Merge main branch with Noah branch>\033[0m\n" `git merge Noah`
	@printf "\033[1;34m<Push the modif>\033[0m\n" `git push`
	@printf "\033[1;34m<Go to Noah branch>\033[0m\n" `git checkout Noah`
	@printf "\033[1;34m<Merge Noah branch with main branch>\033[0m\n" `git merge main`
	@printf "\033[1;34m<Push the modif>\033[0m\n" `git push`

mergeM:
	@printf "\033[1;34m<Go to main branch>\033[0m\n" `git checkout main`
	@printf "\033[1;34m<Pull main branch modif>\033[0m\n" `git pull`
	@printf "\033[1;34m<Merge main branch with Martin branch>\033[0m\n" `git merge Martin`
	@printf "\033[1;34m<Push the modif>\033[0m\n" `git push`
	@printf "\033[1;34m<Go to Martin branch>\033[0m\n" `git checkout Martin`
	@printf "\033[1;34m<Merge Martin branch with main branch>\033[0m\n" `git merge main`
	@printf "\033[1;34m<Push the modif>\033[0m\n" `git push`

mergeV:
	@printf "\033[1;34m<Go to main branch>\033[0m\n" `git checkout main`
	@printf "\033[1;34m<Pull main branch modif>\033[0m\n" `git pull`
	@printf "\033[1;34m<Merge main branch with Victor branch>\033[0m\n" `git merge Victor`
	@printf "\033[1;34m<Push the modif>\033[0m\n" `git push`
	@printf "\033[1;34m<Go to Victor branch>\033[0m\n" `git checkout Victor`
	@printf "\033[1;34m<Merge Victor branch with main branch>\033[0m\n" `git merge main`
	@printf "\033[1;34m<Push the modif>\033[0m\n" `git push`

clear:
	@printf "[\033[31mSuppression\033[m][Déchets]% 48s\n" `$(RM) */*~ *~ */*#* *#* *.o | wc -l | tr -d "'"` | tr " " "."

clean:
	@printf "[\033[31mSuppression\033[m][OBJS]% 51s\n" `$(RM) $(OBJS) | wc -l | tr -d "'"` | tr " " "."
	@printf "[\033[31mSuppression\033[m][OBJS_TEST]% 46s\n" `$(RM) $(OBJS_TEST) | wc -l | tr -d "'"` | tr " " "."

fclean: clean clear
	@printf "[\033[31mSuppression\033[m][Exe]% 52s\n" `$(RMM) $(NAME)` '$(NAME)' | tr " " "."
	@printf "[\033[31mSuppression\033[m][Tests]% 50s\n" `$(RMM) $(NAME_TEST)` '$(NAME_TEST)' | tr " " "."
	@printf "[\033[31mSuppression\033[m][Archive]% 48s\n" `$(RMM) $(ARCH_NAME) $(ARCH_NAME2)` '$(ARCH_NAME)' | tr " " "."
	@$(MAKE) -C lib mclean

re:	fclean
	make -j4 all

# Theses rules do not directly map to a specific file
.PHONY: all clean fclean re exe exa
