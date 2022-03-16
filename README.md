# UnrealPortfolio_3
* 이전에 작성했던 MiniProjet 중 하나를 node.js를 학습하면서 체감한 모듈화(기능 분리)를 중점으로 리팩터링 한 예제
* 악기(instrument)객체는 자체 기능으로 수동연주와 자동연주 기능을 가지고 있다.
* 악기(instrument)객체는 [음원 창고 객체],[악보 기록 및 가공 컴포넌트]를 가지고 있다.
  * [음원 창고 객체 = ASoundWarehouse, 악보 기록 가공 컴포넌트 = USoundRecoder]
  * [음원창고 class를 상속한 객체로 손쉬운 음원 커스텀 가능]
* instrument를 상속한 instrument_Piano객체는 건반 색 변경 기능을 추가하고 오버라이드한 PlayInstrument에 추가하였다.
  * [instrument_Piano의 음원 창고 객체 = ASoundWarehouse를 상속한 BP_pianoSoundWarehouse로 교체]

@ UI 부분과 건반 부분은 시간이 부족하여 자동화하지 못하였습니다. 차후 시간이 나는데로 자동화 예정입니다.

# 읽어주셔서 감사합니다!!
