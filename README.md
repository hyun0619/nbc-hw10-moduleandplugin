# 🎮 Unreal Engine 5: Custom Module & Plugin System

언리얼 엔진 5(UE5) 환경에서 **C++ 커스텀 모듈**을 설계하고 이를 재사용 가능한 **플러그인(Plugin)** 형태로 확장 구현한 실습 프로젝트입니다.

---

## 📌 핵심 학습 목표
1. **언리얼 빌드 시스템 이해**: `Build.cs`와 `Target.cs` 설정을 통한 모듈 단위 빌드 프로세스 숙달
2. **모듈화(Modularity)**: 소스 코드를 논리적 단위로 분리하여 유지보수성 및 컴파일 속도 최적화
3. **플러그인 아키텍처**: 특정 기능을 독립적인 패키지로 구성하여 프로젝트 간 이식성 확보
4. **모듈 간 상호작용**: API 매크로를 활용한 모듈 간 클래스 참조 및 런타임 액터 스폰 구현

---

## 📂 프로젝트 구조 및 주요 단계

### 1️⃣ 커스텀 모듈 `MySpartaLog` 생성
- **모듈 정의**: `Source/MySpartaLog` 경로에 `Build.cs`, 인터페이스(`StartupModule`, `ShutdownModule`) 구현
- **로그 카테고리**: `DECLARE_LOG_CATEGORY_EXTERN`을 사용하여 외부 모듈에서도 접근 가능한 전용 로그 카테고리 생성

### 2️⃣ 모듈 빌드 및 프로젝트 연결
- **Target 설정**: `ModuleAndPlugin.Target.cs`에서 `ExtraModuleNames`에 커스텀 모듈 추가
- **프로젝트 설정**: `.uproject` 파일의 `Modules` 항목에 등록하고 `PreDefault` 로딩 페이즈를 설정하여 기초 시스템 선행 로드 보장

### 3️⃣ 모듈 간 상호작용 (`TestActor`)
- **기능**: `MySpartaLog` 모듈에 속한 `ATestActor` 클래스가 생성될 때 로그를 출력하도록 설계
- **연동**: 주 게임 모듈(`ModuleAndPlugin`)의 캐릭터 클래스에서 플러그인의 액터를 `SpawnActor`로 호출하여 정상 작동 검증

### 4️⃣ 플러그인 `MyNBCLog`로 확장
- **독립화**: 기존 모듈을 `Plugins/MyNBCLog` 경로로 이동하여 프로젝트 독립적인 구조
