# CMake 공부중 <sup>[블로그 참고](https://blog.naver.com/lifeisforu)</sup>
## 1. 튜토리얼
[파일](/c/CMakeStudy/tutorial1_cmake_start/)
CMakeLists.txt파일 및 cmake명령어 사용법?
cmake -S 소스트리 -B 빌드트리 -G 빌드시스탬 선택(나는 안씀...)
## 2. 정적라이브러리
[파일](/c/CMakeStudy/tutorial2_static_library/)
정적 라이브러리 생성 및 링크
cmake --build 빌드할 폴더 --config 나중에 나온다고함....
정적 라이브러리 사용할 때 CMakeLists.txt를 어떻게 작성해야 하는지
## 3. 동적 라이브러리
[파일](/c/CMakeStudy/tutorial3_shared_library/)
동적라이브러리 생성 및 링크(단 블로그에서는 MS기준이라 GCC용으로 찾아서 추가함)
정적 라이브러리 사용할 때 CMakeLists.txt를 어떻게 작성해야 하는지
동적 라이브러리용 헤더파일 작성 요령(이때 컴파일러마다 좀 다름 주의)
name mangling이란 무엇인지 안알려주지만 이거 알아야 동적 라이브러리 작성 할 수 있음...