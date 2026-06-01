#include <WiFi.h>
#include <WebServer.h>

// --- Network Credentials ---
const char* ssid = "ESP32_Joystick_Car";
const char* password = "123";

WebServer server(80);

// --- Pin Definitions (D-Labels) ---
const int STBY_PIN = 13; 
const int IN1 = 33; const int IN2 = 25; const int PWMA = 32; // Drive
const int IN3 = 27; const int IN4 = 14; const int PWMB = 26; // Steering

// --- HTML & CSS & JS (The Interface) ---
String htmlPage = R"rawliteral(
<!DOCTYPE html><html>
<head><meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no">
<style>
  body { font-family: sans-serif; text-align: center; background: #121212; color: white; margin: 0; overflow: hidden; }
  .container { display: flex; flex-direction: column; align-items: center; justify-content: center; height: 100vh; }
  .grid { display: grid; grid-template-columns: 80px 80px 80px; gap: 15px; }
  .btn { width: 80px; height: 80px; background: #333; border: 2px solid #00ffcc; border-radius: 50%; color: white; 
         font-size: 24px; display: flex; align-items: center; justify-content: center; user-select: none; -webkit-tap-highlight-color: transparent; }
  .btn:active { background: #00ffcc; color: black; box-shadow: 0 0 20px #00ffcc; }
  .center { border: none; background: none; font-size: 14px; color: #666; }
</style>
</head>
<body>
  <div class="container">
    <h2>ESP32 JOYSTICK</h2>
    <div class="grid">
      <div></div>
      <div class="btn" ontouchstart="cmd('F')" ontouchend="cmd('S')">▲</div>
      <div></div>
      <div class="btn" ontouchstart="cmd('L')" ontouchend="cmd('BB')">◀</div>
      <div class="center">DRIVE</div>
      <div class="btn" ontouchstart="cmd('R')" ontouchend="cmd('BB')">▶</div>
      <div></div>
      <div class="btn" ontouchstart="cmd('B')" ontouchend="cmd('S')">▼</div>
      <div></div>
    </div>
  </div>
  <script>
    function cmd(c) { fetch('/' + c); }
    // Prevent zoom/scroll on mobile
    document.addEventListener('touchstart', function(e) { if(e.touches.length > 1) e.preventDefault(); }, {passive: false});
  </script>
</body>
</html>
)rawliteral";

// --- Server Handlers ---
void handleRoot() { server.send(200, "text/html", htmlPage); }

void setup() {
  Serial.begin(115200);
  pinMode(STBY_PIN, OUTPUT); digitalWrite(STBY_PIN, HIGH);
  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT); pinMode(PWMA, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT); pinMode(PWMB, OUTPUT);

  WiFi.softAP(ssid, password);
  Serial.println("AP Started. Connect to: ESP32_Joystick_Car");
  Serial.println(WiFi.softAPIP());

  server.on("/", handleRoot);
  server.on("/F", [](){ digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW); analogWrite(PWMA, 220); server.send(200); });
  server.on("/B", [](){ digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH); analogWrite(PWMA, 220); server.send(200); });
  server.on("/S", [](){ digitalWrite(IN1, LOW); digitalWrite(IN2, LOW); analogWrite(PWMA, 0); server.send(200); });
  server.on("/L", [](){ digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW); analogWrite(PWMB, 255); server.send(200); });
  server.on("/R", [](){ digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH); analogWrite(PWMB, 255); server.send(200); });
  server.on("/BB", [](){ digitalWrite(IN3, LOW); digitalWrite(IN4, LOW); analogWrite(PWMB, 0); server.send(200); });

  server.begin();
}

void loop() {
  server.handleClient();
}