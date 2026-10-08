# Linux & Git 치트시트 (Cheat Sheet)

## 1. 핵심 개념 요약
  - **커널 (Kernel)** : 하드웨어를 직접 다루는 운영체제의 핵심부
  - **셸 (Shell)** : 사용자의 명령을 해석해 커널에 전달하는 통역사 프로그램
  - **배포판(Distribution)** : 커널에 명령어, 패키지 관리자를 묶은 완제품 (Ubuntu 24.04 LTS)

## 2. 실습 환경 구축 및 vim 에디터
  - wsl --install -d Ubuntu-24.04
  - sudo apt update
  - sudo apt install -y vim git openssh-server build-essential
  - cat /etc/os-release | head -1

