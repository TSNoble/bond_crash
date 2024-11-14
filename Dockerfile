FROM ros:humble

SHELL ["/bin/bash", "-c"]
RUN apt-get update && apt-get install uuid-dev -y

WORKDIR /workspace

RUN git clone https://github.com/ros/bond_core.git
RUN cd bond_core && git checkout 3.0.2

COPY bond_crash bond_crash

RUN source /opt/ros/humble/setup.bash && colcon build
