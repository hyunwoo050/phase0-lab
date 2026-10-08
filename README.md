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
  - find : 파일이나 디렉터리를 조건에 따라 검색

  - 디렉터리
    - / (root) : 모든 디렉터리의 뿌리, 최상위 시작점
    - /home : 사용자별 개인 작업 및 저장 공간
    - /etc : 시스템 설정 파일 모음
    - /var : 로그, 캐시 등 크기가 계속 변하는 가변 데이터 저장소
    - /proc : 커널이 실시간 상태를 파일처럼 보여주는 가상 디렉터리
    - /dev : 디스크, 터미널 같은 하드웨어 장치들을 파일 형태로 관리
    - /bin, /usr/bin : ls, cat 등 기본 실행 프로그램 본체 저장소
    - /tmp : 임시 파일 저장소, 재부팅하면 내부 데이터가 삭제됨

  - 권한 관리
    - 동작 권한 : r (읽기=4), w (쓰기=2), x (실행=1)
    - 권한 대상 : 소유자(User), 그룹(Group), 기타(Others)
    - chmod : 권한 변경 (chmod 755 report.sh => -rwxr-xr-x)
      - -(d) : 일반 파일(디렉터리)
      - rwx(7) : 소유자 권한(읽기/쓰기/실행)
      - r-x(5) : 그룹 권한(읽기/실행)
      - r-x(5) : 기타 권한(읽기/실행)
    - chown : 소유자 변경 (sudo chown root:root report.sh)
      - sudo : 관리자 권한으로 명령 실행

## 4. 프로세스 및 시그널
  - ps aux : 시스템에서 실행 중인 모든 프로세스 상세 출력
  - ps aux | grep top_ip.sh : 특정 프로세스의 PID(Process ID) 확인
  - top : 실시간 CPU/메모리 사용량 및 프로세스 모니터링 (종료 시 q)
  - kill (-15) <PID> : 프로세스 정상 종료 시그널(SIGTERM) 송신
  - kill -9 <PID> : 프로세스 강제 종료 시그널(SIGKILL) 송신

  - 백그라운드 제어 명령어
    - & : 백그라운드 작업으로 실행 (sleep 300 &)
    - jobs : 현재 터미널 창에서 백그라운드로 실행 중인 작업 목록 확인
    - fg %<작업번호> : 백그라운드에 있는 작업을 화면 앞으로 가져오기
    - nohup <명령어> & : SSH 접속이 끊겨도 백그라운드에서 끊기지 않게 실행 (nohup ./long_task.sh &)

## 5. 표준 입출력, 파이프 & 텍스트 처리
  - 표준 입력(stdin, 0), 표준 출력(stdout, 1), 표준 오류(stderr, 2)

  - 리다이렉션 및 파이프
    - > : 덮어쓰기 (echo "hello" > a.txt)
    - >> : 이어쓰기 (echo "world" >> a.txt)
    - 2> : 오류만 저장 (ls /no_such_dir 2> err.txt)
    - | : 앞 출력을 뒤 입력으로 연결 (sort ip.txt | uniq -c | sort -rn | head -3)
      - sort : 동일 IP를 모아주기 위해 정렬
      - uniq -c : 중복된 IP 개수 계산
      - sort -rn : 개수 기준 숫자(n) 내림차순(r) 정렬
      - head -3 : 위에서 3줄만 출력

  - 텍스트 처리
    - grep : 줄 고르기 (grep "error" app.log)
    - sed : 글자 바꾸기 (sed "s/old/new/g" file.txt)
    - awk : 열 단위로 자르기 (awk "{print \$1}" access.log)

## 6. Git & GitHub
  - Commit & branch Workflow
    - git init : 로컬 저장소 초기화
    - git switch -c <name> : 새로운 브랜치 생성 후 이동
    - gid add <file> : 작업 디렉터리의 변경 사항을 스테이징 영역에 추가
    - git commit -m "message" : 커밋 생성
    - git push origin <name> : 로컬 커밋을 원격 저장소(GitHub)에 브랜치 전송

  - 충돌(Conflict) 해결 프로세스
    - git switch main : 'main' branch로 이동
    - git merge <name> : <name> branch 의 변경을 현재 branch 로 합침
    - 코드 내 충돌 표시 수동 확인
      - vim 에디터로 충돌이 난 파일을 열어 확인
      - <<<<<<< HEAD
        현재 브랜치(main)의 코드
        =======
        합치려는 브랜치(<name>)의 코드
        >>>>>>> <name>
        ...
    - 코드 조율 및 저장 (:wq)
    - git add <file> : 충돌 해결 상태 반영
    - git commit -m "resolve conflict" : 충돌 해결을 마무리하는 머지 커밋 완료
    - git log --oneline : 한 줄 로그를 통해 머지 커밋 확인

  - GitHub Pull Request (PR)
    - 
