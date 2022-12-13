유닉스시스템 프로젝트
========================
사물함 관리 프로그램
------------------------

2022학년도 2학기 전북대학교 공과대학 IT정보공학과 유닉스시스템 과목 프로젝트 리포지토리입니다.   
본 리포지토리에는 프로젝트가 진행되는 과정에 따라 소스코드와 토론 내용들이 지속적으로 업데이트 될 예정입니다.

***

### 프로젝트 개요 (사물함 관리 프로그램)

#### 목표
* 서버-클라이언트 모델로 동작하는 사물함 관리 시스템
* 서버는 사물함을 관리하는 역할을 수행하고, 클라이언트는 사물함 관리 시스템의 고객 역할을 수행한다.
* 서버는 클라이언트들에게 사물함 제공 및 비밀번호 설정을 할 수 있도록 한다.
* 클라이언트는 사물함 사용 및 비밀번호 설정을 수행한다.

#### 필수 기본 기능
##### 서버
* 사용자에게 사물함에 대한 정보 제공.
* 사용자에게 사물함 할당 시 패스워드를 지정하도록 함.
* 사용자가 본인 사물함에 접근 시 입력하는 패스워드가 맞는 지 확인하고, 맞으면 접근 가능하도록 함.
* 내용물을 저장함.

##### 클라이언트
* 원하는 사물함에 접근.
* 해당 사물함의 비밀번호 설정 및 입력 기능
* 내용물 입력

#### 추가한 기능
* 서버를 실행할 때마다 클라이언트에게 제공할 사물함의 개수를 설정함.
* 동시에 여러 사용자가 서버에 접근하고 사물함 정보를 실시간으로 반영할 수 있도록 함.
* 클라이언트가 비밀번호를 변경할 수 있는 기능을 제공.
* 사물함 접근 시 3회 PW를 틀리면 사물함에 접근할 수 없도록 함.
* 사물함 접근 시 3회 PW를 틀리면 서버에 알림이 가도록 만듦.
* 비밀번호 설정 시 실수가 없도록 2차 확인 과정을 제공.
* 사물함 사용을 종료했을 경우 해당 칸의 비밀번호 초기화.
* 사물함 접근 후 사물함에 들어있는 내용을 변경할 수 있는 기능 제공.
* 전체 사물함 상태를 띄우는 기능을 제공.
* 레코드 잠금 기능을 활용, 동시에 여러 사용자가 서버에 접근하더라도 레코드에 손상이 가지 않도록 함.

#### 추가할 기능
* (+) 클라이언트에게 여러 종류의 사물함을 제공한다.
  + 사물함 종류마다 들어갈 수 있는 사물의 수를 지정해 둔다.
* (+) 한 사물함에 물건이 여러 개 들어있을 때 몇 개의 사물만 뺄 수 있는 기능을 넣는다.
* (+) 클라이언트 명령에서 특정 명령 입력 시 관리자 모드로 진입할 수 있는 기능을 만든다.
  + 관리자 모드에서는 특정 사물함의 정보를 가져오거나 강제로 비우게 할 수 있다.

#### 특징
* 서버가 재실행 될 때마다 사물함 정보가 초기화된다. (서버 실행과 동시에 생성할 사물함 개수를 서버 콘솔로 입력받는다.)

***

### 사용법

#### 소스파일 설명
* check.c, check.h : 서버 사물함이 사용중인지 아닌지 판단하는 소스파일
* client.c : 서버에 연결하기 위한 클라이언트 소스파일
* client_management.c, client_management.h : 클라이언트가 수행하는 역할이 수록된 소스파일
* locker.h : 사물함 구조체가 선언된 헤더파일
* manage.c, manage.h : 서버 사물함을 관리하기 위한 소스파일
* management.c, management.h : 서버가 수행하는 역할이 수록된 소스파일
* readline.c, readline.h : 소켓 파일 디스크립터에서 한 줄의 문장을 읽어오는 코드가 수록된 소스파일
* server.c : 클라이언트의 연결을 받기 위한 서버를 여는 소스파일
* store.c, store.h : 사물함에 물건을 보관하기 위한 소스파일

#### 컴파일
* 서버 : source 디렉토리 안에서 gcc -o ../exec/server server.c check.c manage.c management.c readline.c store.c
* 클라이언트 : source 디렉토리 안에서 gcc -o ../exec/client client.c check.c client_management.c manage.c readline.c store.c
* 프로그램 실행 : exec 디렉토리 안에서 서버 선 실행 -> ./server 후 클라이언트 실행 -> ./client

***

### 22-12-07 (수)

#### 진행 상황
* 서버와 클라이언트가 UNIX address를 통해 정보를 송수신하는 기본 토대 제작.

#### 노트
* 

***

### 22-12-08 (목)

#### 진행 상황
* 서버를 실행하면 사물함 개수를 설정할 수 있도록 하는 기능 제작.
  + 변수와 포인터는 각각 함수로 넘겨 입력받을 때, 포인터와 더블포인터로 넘겨서 Call-By-Adress 방식을 거쳐야 한다.
* 클라이언트가 서버에 정보를 cstring으로 넘기는 방법 구현

#### 노트
* PC에 있는 파일에 사물함 정보를 저장하여 프로그램을 껐다가 키더라도 정보가 유지될 수 있도록 만드는 기능 추가 제안
* 클라이언트 로그인 방식 제안
* (-) 서버를 열고, 사물함을 생성할 때마다 사물함 각각에 동적 할당을 하여 불필요한 메모리 낭비를 줄이는 기능
  + 클라이언트 로그인 방식과 공존하기 힘들다고 판단됨.
* 클라이언트당 최대 사용가능한 사물함 수에 제한을 둔다.
* 한 사물함에 물건이 여러 개 들어있을 때 몇 개의 사물만 뺄 수 있는 기능을 넣는다.
* 내용물을 모두 꺼내지 않고 사물함 사용을 종료했을 경우 서버에서 사물함 사용 종료를 막는다.
* 서버 콘솔에서 특정 명령 입력 시 모든 사물함 정보 디스플레이
* 서버 콘솔에서 특정 명령 입력 시 모든 사물함 정보 초기화

***

### 22-12-09 (금)

#### 문제점
* 알 수 없는 오류로 인해 프로그램 실행이 되지 않음. 소스파일이 상당히 더럽고 양이 많은 관계로 디버깅이 불가능하다고 판단함.
* 시간 문제로 인해 전부 다 지우고 처음부터 다시 하자는 제안, 프로젝트 리셋 후 재시작.

***

### 22-12-10 (토)

#### 진행 상황
* 클라이언트-서버 소켓 통신 기본 모델 설계 및 제작
  + server.c, client.c에 기본 내용들 투입.
* 주된 행위가 있는 것 단위로 소스 파일을 나눠야겠다는 의견 수렴.
  + 서버와 클라이언트 계정을 관리하는 소스파일 management.c, client_management.c 설계 및 제작
    - management.c는 서버 기본 설정(실행 직후 몇 개의 사물함을 제공할 것인지 정하는 행위 등)을 도와준다.
    - 서버가 클라이언트로부터 받은 요구를 들어줄 수 있도록 check.c, store.c, manage.c로 이어주는 연결다리 역할을 한다.
    - client_management.c는 클라이언트가 하는 요구를 보조하는 소스파일로의 연결다리 역할을 한다.
* 주된 행위를 크게 세 가지로 나누고, 세 가지 소스 파일에 서버와 클라이언트가 실행할 소스 코드를 넣음.
  + check.c, store.c, manage.c 세 개로 나누고 제작 예정.

#### 노트
* strcat은 dest string의 총 할당 크기가 depart string이 삽입되고도 남는 크기여야 정상 실행이 된다.

***

### 22-12-11 (일)

#### 진행 상황
* 서버 사물함이 비었는지, 사용 중인지 확인할 수 있는 check 기능 구현. (check.c)
  + 바이너리 파일을 활용, 파일에 "00001001010"식으로 기록된 자료를 가져온다.
  + 0은 비어있는 사물함, 1은 사용 중인 사물함을 뜻한다.
* 서버 사물함에 물건을 넣는 store기능 구현. (store.c)
  + 바이너리 파일 활용 기반, 레코드 작성, 접근, 업데이트를 활용했다.
  + 서버는 클라이언트에게 사용 가능한 사물함을 뽑아 알려준다.
  + 클라이언트가 이미 사용 중인 사물함을 고르거나, 접근이 불가능한 사물함 번호를 고른다면 경고를 띄운다.
  + 올바른 사물함을 고른다면, 넣을 물건을 기입한 뒤 비밀번호를 입력한다.
  + 비밀번호 확인 기능을 넣어 비밀번호 기입 시 실수가 없도록 도와준다.
* 자신의 물건이 들어있는 사물함을 관리할 수 있는 manage기능 구현. (manage.c)
  + 관리할 사물함 번호를 입력한다.
  + 비어 있는 사물함을 고르거나, 접근이 불가능한 사물함 번호를 고른다면 경고를 띄운다.
  + 물건이 들어 있는 사물함을 고른다면, 비밀번호를 요구한다.
  + 잘못된 비밀번호를 3회 이상 입력한다면 메뉴로 돌아가도록 만든다.
  + 올바른 비밀번호를 입력한다면 사물함 정보(들어있는 물건과 비밀번호)를 띄우고, 3가지 기능을 제공한다.
  + 물건 빼기, 물건 교체하기, 비밀번호 변경하기 기능을 제공한다.
  + 물건을 빼면 해당 사물함은 빈 사물함이 된다.
  + 물건을 교체하면 해당 사물함의 물건이 바뀐다.
  + 비밀번호를 변경하면 해당 사물함의 비밀번호가 바뀐다. 이 또한 확인 기능으로 실수가 없도록 도와준다.
  
#### 노트
*   

***

### 22-12-12 (월)

#### 진행 상황
* 읽기/쓰기 레코드 잠금을 활용함.
  + 여러 사용자가 한 파일에 대해 중복으로 쓰거나 변경을 시도하는 일을 막음.
  + 이를 통해 완벽하게 여러 사용자를 문제 없이 받을 수 있는 서버가 구현됨.
* 임의의 사용자가 임의의 잠긴 사물함에 3번 패스워드 입력에 실패할 시, 서버에 알림이 가도록 만듦.

#### 노트
* 날려먹은 시간이 너무 아깝다. 구현하지 못한 관리자 계정과 여러 종류 사물함이 아쉽게 느껴진다.

***

### 22-12-13(화)

#### 진행 상황
* 프로젝트 마감, 발표
