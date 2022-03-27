# MiniPiano
* 이전에 작성했던 MiniProjet 중 하나를 node.js를 학습하면서 체감한 모듈화(기능 분리)를 중점으로 리팩터링 한 예제

* 악기(instrument)객체는 [음원 창고 객체],[악보 기록 및 가공 컴포넌트]를 가지고 있다.
  * [음원 창고 객체 = ASoundWarehouse, 악보 기록 가공 컴포넌트 = USoundRecoder]
  * [음원창고 class를 상속한 객체로 손쉬운 음원 커스텀 가능]
* 악기(instrument)객체는 자체기능으로 수동연주와 자동연주 기능을 가지고 있다.
* 악기(instrument)객체는 최종적으로 자체기능과 컴포넌트들의 기능을 엮는다. [컨트롤러 역할]
* instrument를 상속한 instrument_Piano객체는 건반 색 변경 기능을 추가하고 오버라이드한 PlayInstrument에 추가하였다.
  * [instrument_Piano의 음원 창고 객체 = ASoundWarehouse를 상속한 BP_pianoSoundWarehouse로 교체]

* 이미지 설명
* <img src="https://user-images.githubusercontent.com/66342017/160290776-d87e8234-3af2-4dce-a0b0-b8a028e651a2.JPG"  width="800" height="500">

* [영상 링크](https://youtu.be/UFiNWYKLHcU)
* [포트폴리오 링크](https://special-room-7d9.notion.site/Resume-7a2d71247075470ba8854fb68c9e1a08)
* [프로젝트 빌드 파일](https://drive.google.com/file/d/1ceUhLh5ZK_lcmrECHIuNZRDHF_h1BBDZ/view?usp=sharing)
  *  [ 빌드 파일 Play 설명 ] 
  *  Tab 키 입력 모드 변경 [ 화음모드, 단음모드 ]
  *  건반 키 입력 오른쪽 숫자 키패드 [ 0 1 2 3 4 5 6 7 8 9 ]
  *  종료키 [ alt + f4 ]
  *  레코드 체크 == 키 입력 기록
  *  레코드 체크 해제 == 기록된 키 입력, 악보로 출력
  *  Play == 악보에 적힌 정보에 따라 자동 연주

# 읽어주셔서 감사합니다!!
