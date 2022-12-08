유닉스시스템 프로젝트
========================
사물함 관리 프로그램
------------------------

2022학년도 2학기 IT정보공학과 유닉스시스템 과목 프로젝트 리포지토리입니다.   
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
* 사물함 사용을 종료했을 경우 해당 칸의 비밀번호 초기화

##### 클라이언트
* 원하는 사물함에 접근.
* 해당 사물함의 비밀번호 설정 및 입력 기능
* 내용물 입력

#### 추가 기능
* 동시에 여러 사용자가 서버에 접근하고 사물함 정보를 실시간으로 반영할 수 있도록 한다. (중요)
* 클라이언트에게 여러 종류의 사물함을 제공한다.
  + 사물함 종류마다 들어갈 수 있는 사물의 수를 지정해 둔다.
* (+) PC에 있는 파일에 사물함 정보를 저장하여 프로그램을 껐다가 키더라도 정보가 유지될 수 있도록 만드는 기능
* (+) 클라이언트가 사물함 서버에 접근할 때부터 본인임을 알 수 있도록 함 (서버 로그인 방식)
  + 위 방법을 사용할 시, 접속과 동시에 현재 내가 사용중인 사물함의 번호와 내용물을 알 수 있도록 도와주는 기능 제공
  + 위 방법을 사용할 시, 다른 사람의 사물함에는 아예 접근하지 못하는 기능을 만들 수 있다.
* 클라이언트가 비밀번호를 변경할 수 있는 기능을 넣는다.
* 비밀번호 설정 시 비밀번호 확인 기능을 넣는다.
* 사물함 접근 시 여러 번 PW를 틀리면 사물함에 일정 시간 접근하지 못하도록 막고, 서버에 알림을 준다.
* 클라이언트당 최대 사용가능한 사물함 수에 제한을 둔다.
* 한 사물함에 물건이 여러 개 들어있을 때 몇 개의 사물만 뺄 수 있는 기능을 넣는다.
* 내용물을 모두 꺼내지 않고 사물함 사용을 종료했을 경우 서버에서 사물함 사용 종료를 막는다.
* 서버 콘솔에서 특정 명령 입력 시 모든 사물함 정보 디스플레이

***

### 22-12-07 (수)

#### 프로그램 토대 제작
* 서버와 클라이언트가 UNIX address를 통해 정보를 송수신하는 기본 토대 제작.

***

### 22-12-08 (목)

#### 브레인스토밍
* PC에 있는 파일에 사물함 정보를 저장하여 프로그램을 껐다가 키더라도 정보가 유지될 수 있도록 만드는 기능 추가 제안
* 클라이언트 로그인 방식 제안
* (-) 서버를 열고, 사물함을 생성할 때마다 사물함 각각에 동적 할당을 하여 불필요한 메모리 낭비를 줄이는 기능
  + 클라이언트 로그인 방식과 공존하기 힘들다고 판단됨.
* 서버 콘솔에서 특정 명령 입력 시 모든 사물함 정보 디스플레이
