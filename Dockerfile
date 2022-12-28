FROM ubuntu:latest

RUN apt-get update -y
RUN apt-get install -y
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
RUN mv libmlx_Linux.a /usr/local/lib/
RUN apt-get install xrdp xfce4 xfce4-goodies -y
RUN sed -i 's/3389/8000/g' /etc/xrdp/xrdp.ini
RUN sed -i 's/max_bpp=32/#max_bpp=32\nmax_bpp=128/g' /etc/xrdp/xrdp.ini
RUN sed -i 's/xserverbpp=24/#xserverbpp=24\nxserverbpp=128/g' /etc/xrdp/xrdp.ini
RUN echo xfce4-session > ~/.xsession
RUN sed -i 's/test -x \/etc\/X11\/Xsession && exec \/etc\/X11\/Xsession/#test -x \/etc\/X11\/Xsession && exec \/etc\/X11\/Xsession/g' /etc/xrdp/startwm.sh
RUN sed -i 's/exec \/bin\/sh \/etc\/X11\/Xsession/#exec \/bin\/sh \/etc\/X11\/Xsession\n#Xfce4\nstartxfce4/g' /etc/xrdp/startwm.sh
#CMD ["/etc/init.d/xrdp", "start"]
RUN useradd -m solong && echo "solong:game" | chpasswd && adduser solong sudo && addgroup solong sudo

EXPOSE 8000

WORKDIR /prod

CMD ["tail", "-f", "/dev/null"]