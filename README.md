# MiniPiano
* 이전에 작성했던 MiniProjet 중 하나를 node.js를 학습하면서 체감한 모듈화(기능 분리)를 중점으로 리팩터링 한 예제

* 악기(instrument)객체는 [음원 창고 객체],[악보 기록 및 가공 컴포넌트]를 가지고 있다.
  * [음원 창고 객체 = ASoundWarehouse, 악보 기록 가공 컴포넌트 = USoundRecoder]
  * [음원창고 class를 상속한 객체로 손쉬운 음원 커스텀 가능]
* 악기(instrument)객체는 자체기능으로 수동연주와 자동연주 기능을 가지고 있다.
* 악기(instrument)객체는 최종적으로 자체기능과 컴포넌트들의 기능을 엮는다. [컨트롤러 역할]
* instrument를 상속한 instrument_Piano객체는 건반 색 변경 기능을 추가하고 오버라이드한 PlayInstrument에 추가하였다.
  * [instrument_Piano의 음원 창고 객체 = ASoundWarehouse를 상속한 BP_pianoSoundWarehouse로 교체]

* [영상 링크]()
* [포트폴리오 링크]()
* [프로젝트 빌드 파일]()

# 읽어주셔서 감사합니다!!
