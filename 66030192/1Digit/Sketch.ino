// กำหนดขา GPIO ของ ESP32 ที่เชื่อมต่อกับแต่ละ segment ของ 7-segment display
const int SEG_A = 19;
const int SEG_B = 18;
const int SEG_C = 5;
const int SEG_D = 17;
const int SEG_E = 16;
const int SEG_F = 4;
const int SEG_G = 0;


// Array เก็บสถานะ HIGH/LOW สำหรับแต่ละ segment เพื่อแสดงตัวเลข 0-9
// รูปแบบ: {a, b, c, d, e, f, g} (DP ไม่รวมในชุดนี้)
// สำหรับ Common Cathode: HIGH = เปิด, LOW = ปิด
byte seven_seg_digits[10][7] = {
  //   a, b, c, d, e, f, g
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

void setup() {
  // กำหนดขา GPIO ทั้งหมดเป็น OUTPUT
  pinMode(SEG_A, OUTPUT);
  pinMode(SEG_B, OUTPUT);
  pinMode(SEG_C, OUTPUT);
  pinMode(SEG_D, OUTPUT);
  pinMode(SEG_E, OUTPUT);
  pinMode(SEG_F, OUTPUT);
  pinMode(SEG_G, OUTPUT);
}

void loop() {
  // วนลูปแสดงตัวเลข 0-9 เท่านั้น
  for (int digit = 0; digit < 10; digit++) { // เปลี่ยนเงื่อนไขจาก < 16 เป็น < 10
    displayDigit(digit);
    delay(1000); // หน่วงเวลา 1 วินาที
  }
}

// ฟังก์ชันสำหรับแสดงตัวเลขบน 7-segment display
void displayDigit(int digit) {
  digitalWrite(SEG_A, seven_seg_digits[digit][0]);
  digitalWrite(SEG_B, seven_seg_digits[digit][1]);
  digitalWrite(SEG_C, seven_seg_digits[digit][2]);
  digitalWrite(SEG_D, seven_seg_digits[digit][3]);
  digitalWrite(SEG_E, seven_seg_digits[digit][4]);
  digitalWrite(SEG_F, seven_seg_digits[digit][5]);
  digitalWrite(SEG_G, seven_seg_digits[digit][6]);
}
