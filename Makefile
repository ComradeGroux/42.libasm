GREENGREEN = \033[38;5;46m
RED = \033[0;31m
GREY = \033[38;5;240m
RESET = \033[0m

NAME = libasm

NAME_LIB = libasm.a

DIR_S = srcs/
DIR_O = objs/

SRCS_LIST = 	ft_write.s \
		ft_read.s \
		ft_strcmp.s \
		ft_strcpy.s \
		ft_strdup.s \
		ft_strlen.s

TESTER = test

CC = gcc

CFLAGS = -Wall -Wextra -Werror -no-pie #The -no-pie flag is important otherwise it would not compile

NASM = nasm

NASMFLAGS = -f elf64

SRCS =		${addprefix ${DIR_S}, ${SRCS_LIST}}

OBJS =		${SRCS:${DIR_S}%.s=${DIR_O}%.o}

${DIR_O}%.o : ${DIR_S}%.s
	@mkdir -p ${DIR_O}
	$(NASM) $(NASMFLAGS) $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "$(RESET)[$(GREENGREEN)${NAME}$(RESET)]: ${NAME} Objects were created${GREY}"
	ar rcs $(NAME_LIB) $(OBJS)
	@echo "$(RESET)[$(GREENGREEN)${NAME}$(RESET)]: ${NAME} created !"

test : all
	${CC} ${CFLAGS} main.c -L. -lasm -o ${TESTER}


# ${NAME}: ${OBJS}
# 	nasm ${SRCS} -o ${NAME}.o
# 	ld ${NAME}.o -lSystem -o ${NAME}

clean:
	@echo "$(RED) ██████╗██╗     ███████╗ █████╗ ███╗   ██╗██╗███╗   ██╗ ██████╗$(RESET)"
	@echo "$(RED) ██╔════╝██║     ██╔════╝██╔══██╗████╗  ██║██║████╗  ██║██╔════╝$(RESET)"
	@echo "$(RED) ██║     ██║     █████╗  ███████║██╔██╗ ██║██║██╔██╗ ██║██║  ███╗$(RESET)"
	@echo "$(RED) ██║     ██║     ██╔══╝  ██╔══██║██║╚██╗██║██║██║╚██╗██║██║   ██║$(RESET)"
	@echo "$(RED) ╚██████╗███████╗███████╗██║  ██║██║ ╚████║██║██║ ╚████║╚██████╔╝$(RESET)"
	@echo "$(RED)  ╚═════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═══╝ ╚═════╝ $(RESET)"
	@echo "[$(RED)${NAME}$(RESET)]: Cleaning ${NAME} Objects...${GREY}"
	${RM} ${OBJS}
	${RM} -r ${DIR_O}
	@echo "[$(RED)${NAME}$(RESET)]: ${NAME} Objects were cleaned${GREY}"

fclean: clean
	@echo "${RESET}[$(RED)${NAME}$(RESET)]: Cleaning ${NAME}...${GREY}"
	${RM} ${NAME} ${NAME_LIB}
	${RM} ${TESTER}
	@echo "${RESET}[$(RED)${NAME}$(RESET)]: ${NAME} Executable was cleaned"

re: fclean all

.PHONY: all clean fclean re
