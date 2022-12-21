FROM ubuntu:latest

RUN apt-get update -y
RUN apt-get install -y --no-install-recommends apt-utils
RUN apt-get install gcc -y
RUN apt-get install make -y
RUN apt-get install git -y
RUN apt-get install vim -y
RUN apt-get install clang -y
RUN apt-get install valgrind -y
RUN apt-get install python3 -y
RUN apt-get install python3-venv python3-pip -y
RUN python3 -m pip install --upgrade pip setuptools
RUN python3 -m pip install norminette
RUN apt-get install xorg libxext-dev zlib1g-dev libbsd-dev -y
ENV PATH=${PATH}:/usr/bin/env
ADD /srcs/mlx_linux/ /mlx_linux
WORKDIR /mlx_linux
RUN cp mlx.h /usr/local/include/
RUN mkdir /usr/local/man/man3
RUN cp man/man3/*.3 /usr/local/man/man3
RUN make
RUN mv libmlx_Linux.a /usr/local/lib/


WORKDIR /prod

CMD ["tail", "-f", "/dev/null"]