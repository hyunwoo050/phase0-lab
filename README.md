# Linux & Git 치트시트 (Cheat Sheet)

## 1. 핵심 개념 요약
  - **커널 (Kernel)** : 하드웨어를 직접 다루는 운영체제의 핵심부
  - **셸 (Shell)** : 사용자의 명령을 해석해 커널에 전달하는 통역사 프로그램
  - **배포판(Distribution)** : 커널에 명령어, 패키지 관리자를 묶은 완제품 (Ubuntu 24.04 LTS)
    
## 2. 실습 환경 구축 및 vim 에디터
  - wsl --install -d Ubuntu-24.04 : 윈도우 파워셸에서 Ubuntu 24.04 설치
  - sudo apt update : Ubuntu 패키지 최신화
  - sudo apt install -y vim git openssh-server build-essential : 개발에 필요한 필수 도구 설치
      - vim : vim 에디터
      - git : GitHub 연동 소스코드 관리 도구
      - openssh-server : SSH(Secure Shell) 원격 접속을 위한 서버 프로그램
      - build-essential : 기초적인 빌드 패키지 모음
  - cat /etc/os-release | head -1 : 설치된 리눅스 버전 확인 (PRETTY_NAME="Ubuntu 26.04.1 LTS")

  - sudo service ssh start : SSH 원격 접속 서비스 실행
  - ssh $USER@127.0.0.1 : 내 계정($USER)으로 나 자신(127.0.0.1)에게 원격 접속 시도
  - whoami : 원격 접속이 성공했는지 현재 로그인된 사용자 확인
  - exit : SSH 원격 접속 안전하게 종료 (로그아웃)

  - vim 에디터 명령어
      - i : 입력 모드 (insert)
      - ESC : 일반 모드
      - dd : 한 줄 삭제
      - yy : 한 줄 복사
      - p : 커서 아래 붙여넣기
      - u : 작업 취소 (undo)
      - /text : 문서 안에서 text 검색
      - :wq : 저장하고 종료
      - :q! : 저장하지 않고 강제 종료

## 3. 파일 시스템 & 권한 관리
  - **절대 경로** : 최상위 루트(/) 기준 파일의 고유한 전체 주소 (/etc/hostname)
  - **상대 경로** : 현재 위치(디렉터리) 기준 파일의 주소 (../src)
      - . : 현재 디렉터리
      - .. : 상위 디렉터리
      - ~ : 홈 디렉터리
  - pwd : 현재 작업 중인 디렉터리의 절대 경로 표시
  - cd : 폴더(디렉터리)로 이동
  - ls -la : 숨김 파일을 포함한 상세 정보 출력

