### 객체지향 설계 원칙 SOLID

SOLID 원칙은 **로버트 C. 마틴(Robert C. Martin)**이 정리한 객체지향 설계의 다섯 가지 원칙으로, 유지보수성과 확장성을 고려한 좋은 코드 작성을 위한 기준이 된다.

---

### 1. **단일 책임 원칙(SRP, Single Responsibility Principle)**
- **한 클래스는 하나의 책임만 가져야 한다.**
- 즉, 변경이 필요할 때 한 가지 이유로만 변경되어야 한다.
- 책임이 많으면 변경의 이유가 많아지고, 코드의 유지보수가 어려워진다.

📌 **예시**
```java
class Report {
    void generateReport() { /* 리포트 생성 로직 */ }
    void printReport() { /* 리포트 출력 로직 */ }
}
```
🔻 **위반 예시**
- `generateReport()`와 `printReport()`가 서로 다른 책임(리포트 생성과 출력)을 가지고 있음.

✅ **개선 예시**
```java
class ReportGenerator {
    void generateReport() { /* 리포트 생성 로직 */ }
}

class ReportPrinter {
    void printReport() { /* 리포트 출력 로직 */ }
}
```
- 책임을 분리하여 각각의 클래스가 하나의 역할만 수행하도록 개선.

---

### 2. **개방-폐쇄 원칙(OCP, Open-Closed Principle)**
- **확장에는 열려 있어야 하고, 변경에는 닫혀 있어야 한다.**
- 새로운 기능 추가 시 기존 코드를 변경하지 않고 확장 가능해야 한다.

📌 **위반 예시**
```java
class PaymentService {
    void processPayment(String type) {
        if (type.equals("credit")) {
            // 신용카드 결제 로직
        } else if (type.equals("paypal")) {
            // PayPal 결제 로직
        }
    }
}
```
🔻 **위반**
- 새로운 결제 방식이 추가될 때마다 `processPayment`를 수정해야 함.

✅ **개선 예시 (OCP 적용)**
```java
interface Payment {
    void pay();
}

class CreditCardPayment implements Payment {
    public void pay() { /* 신용카드 결제 로직 */ }
}

class PayPalPayment implements Payment {
    public void pay() { /* PayPal 결제 로직 */ }
}

class PaymentService {
    void processPayment(Payment payment) {
        payment.pay();
    }
}
```
- 새로운 결제 수단이 추가되어도 기존 코드를 변경할 필요 없이 `Payment` 인터페이스만 구현하면 된다.

---

### 3. **리스코프 치환 원칙(LSP, Liskov Substitution Principle)**
- **하위 클래스는 상위 클래스를 대체할 수 있어야 한다.**
- 즉, `부모 클래스의 기능을 하위 클래스가 대체했을 때, 프로그램이 정상적으로 동작해야 한다.`

📌 **위반 예시**
```java
class Rectangle {
    protected int width, height;
    void setWidth(int width) { this.width = width; }
    void setHeight(int height) { this.height = height; }
    int getArea() { return width * height; }
}

class Square extends Rectangle {
    @Override
    void setWidth(int width) { this.width = this.height = width; }

    @Override
    void setHeight(int height) { this.width = this.height = height; }
}
```
🔻 **위반**
- `Square`는 `Rectangle`을 상속했지만 `setWidth()`와 `setHeight()`의 동작이 달라짐.
- `Rectangle`을 사용하는 코드가 `Square`로 대체되었을 때 예측할 수 없는 문제가 발생할 수 있음.

✅ **개선 예시**
- `Rectangle`과 `Square`를 따로 분리하여 상속 대신 **구성(composition)**을 활용하는 것이 좋다.

---

### 4. **인터페이스 분리 원칙(ISP, Interface Segregation Principle)**
- **클라이언트가 사용하지 않는 인터페이스에 의존하지 않아야 한다.**
- 즉, **큰 인터페이스보다는 여러 개의 작은 인터페이스로 나누는 것이 좋다.**

📌 **위반 예시**
```java
interface Worker {
    void work();
    void eat();
}

class Developer implements Worker {
    public void work() { /* 개발 업무 */ }
    public void eat() { /* 점심 시간 */ }
}

class Robot implements Worker {
    public void work() { /* 로봇 업무 */ }
    public void eat() { throw new UnsupportedOperationException("로봇은 먹지 않음"); }
}
```
🔻 **위반**
- `Robot`은 `eat()` 메서드를 구현할 필요가 없음.

✅ **개선 예시 (ISP 적용)**
```java
interface Workable {
    void work();
}

interface Eatable {
    void eat();
}

class Developer implements Workable, Eatable {
    public void work() { /* 개발 업무 */ }
    public void eat() { /* 점심 시간 */ }
}

class Robot implements Workable {
    public void work() { /* 로봇 업무 */ }
}
```
- `Worker` 인터페이스를 `Workable`과 `Eatable`로 분리하여 불필요한 의존성을 제거.

---

### 5. **의존 역전 원칙(DIP, Dependency Inversion Principle)**
- **고수준 모듈(비즈니스 로직)이 저수준 모듈(세부 구현)에 의존해서는 안 된다.**
- **추상화(인터페이스)에 의존해야 하며, 구체적인 구현체에 의존하면 안 된다.**

📌 **위반 예시**
```java
class MySQLDatabase {
    void connect() { /* MySQL 연결 */ }
}

class UserService {
    private MySQLDatabase db = new MySQLDatabase();
    void getUser() { db.connect(); /* 사용자 데이터 조회 */ }
}
```
🔻 **위반**
- `UserService`가 `MySQLDatabase`에 강하게 결합됨.
- 다른 데이터베이스로 교체하려면 `UserService` 코드를 수정해야 함.

✅ **개선 예시 (DIP 적용)**
```java
interface Database {
    void connect();
}

class MySQLDatabase implements Database {
    public void connect() { /* MySQL 연결 */ }
}

class PostgreSQLDatabase implements Database {
    public void connect() { /* PostgreSQL 연결 */ }
}

class UserService {
    private Database db;
    
    public UserService(Database db) { this.db = db; }
    
    void getUser() { db.connect(); /* 사용자 데이터 조회 */ }
}
```
- `Database` 인터페이스를 사용하여 `UserService`가 특정 DB 구현체에 의존하지 않도록 개선.

---

## 🔥 SOLID 원칙 적용의 이점
✅ **유지보수성**: 코드 변경 시 영향을 최소화할 수 있음  
✅ **확장성**: 새로운 기능 추가 시 기존 코드를 수정하지 않아도 됨  
✅ **가독성**: 코드가 깔끔하고 이해하기 쉬워짐  
✅ **유연성**: 인터페이스와 추상화를 통해 코드 변경이 용이  

---

### ✅ 정리
| 원칙 | 개념 |
|------|------|
| SRP (단일 책임 원칙) | 하나의 클래스는 하나의 책임만 가져야 함 |
| OCP (개방-폐쇄 원칙) | 확장에는 열려 있고, 변경에는 닫혀 있어야 함 |
| LSP (리스코프 치환 원칙) | 하위 클래스가 상위 클래스를 대체할 수 있어야 함 |
| ISP (인터페이스 분리 원칙) | 클라이언트가 사용하지 않는 기능에 의존하지 않아야 함 |
| DIP (의존 역전 원칙) | 구체적인 구현이 아닌 추상화에 의존해야 함 |

이 원칙들을 잘 적용하면 유지보수성과 확장성이 뛰어난 객체지향 프로그램을 만들 수 있어! 🚀
