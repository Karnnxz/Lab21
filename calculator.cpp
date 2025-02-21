#include <windows.h>
#include <stdio.h>

HWND textfield,textBox1,textBox2,button;
char text1[20];
char text2[20];

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
 switch(Message) {
  case WM_CREATE:
   textfield = CreateWindow("STATIC", "Please input two numbers", WS_VISIBLE | WS_CHILD, 20, 20, 198, 25, hwnd, NULL, NULL, NULL);
   textBox1 = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD, 40, 50, 150, 25, hwnd, NULL, NULL, NULL);
   textBox2 = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD, 40, 80, 150, 25, hwnd, NULL, NULL, NULL);
   button = CreateWindow("BUTTON", "+", WS_VISIBLE | WS_CHILD, 60, 110, 25, 25, hwnd, (HMENU) 1, NULL, NULL);
   button = CreateWindow("BUTTON", "-", WS_VISIBLE | WS_CHILD, 90, 110, 25, 25, hwnd, (HMENU) 2, NULL, NULL);     
   button = CreateWindow("BUTTON", "*", WS_VISIBLE | WS_CHILD, 120, 110, 25, 25, hwnd, (HMENU) 4, NULL, NULL);
   button = CreateWindow("BUTTON", "/", WS_VISIBLE | WS_CHILD, 150, 110, 25, 25, hwnd, (HMENU) 3, NULL, NULL);
   break;
  case WM_COMMAND:
   if(LOWORD(wParam)!=0){
     int gwtstat1 =0,gwtstat2 =0;
     gwtstat1 = GetWindowText(textBox1,&text1[0],20);
     gwtstat2 = GetWindowText(textBox2,&text2[0],20);
    }
    if(LOWORD(wParam)==1){
     float re=atof(text1)+atof(text2);
     char t[100];
     sprintf(t, "%f", re);
     ::MessageBox(hwnd,t,"Result",MB_OK);
    }
    if(LOWORD(wParam)==2){
     float re=atof(text1)-atof(text2);
     char t[100];
     sprintf(t, "%f", re);
     ::MessageBox(hwnd,t,"Result",MB_OK);
    }
    if(LOWORD(wParam)==3){
     float re=atof(text1)/atof(text2);
     char t[100];
     sprintf(t, "%f", re);
     ::MessageBox(hwnd,t,"Result",MB_OK);
    }
    if(LOWORD(wParam)==4){
     float re=atof(text1)*atof(text2);
     char t[100];
     sprintf(t, "%f", re);
     ::MessageBox(hwnd,t,"Result",MB_OK);
    }
    break;  
  case WM_DESTROY: {
   PostQuitMessage(0);
   break;
  }
  default:
   return DefWindowProc(hwnd, Message, wParam, lParam);
 }
 return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
 WNDCLASSEX wc;
 HWND hwnd;
 MSG msg;

 memset(&wc,0,sizeof(wc));
 wc.cbSize  = sizeof(WNDCLASSEX);
 wc.lpfnWndProc  = WndProc;
 wc.hInstance  = hInstance;
 wc.hCursor  = LoadCursor(NULL, IDC_ARROW);
 wc.hbrBackground = CreateSolidBrush(RGB(139, 0, 0));
 wc.lpszClassName = "WindowClass";
 wc.hIcon  = LoadIcon(NULL, IDI_APPLICATION);
 wc.hIconSm  = LoadIcon(NULL, IDI_APPLICATION);

 if(!RegisterClassEx(&wc)) {
  MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
  return 0;
 }

 hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","My Calculator",WS_VISIBLE|WS_SYSMENU,
  CW_USEDEFAULT,
  CW_USEDEFAULT,
  250,
  200,
  NULL,NULL,hInstance,NULL);

 if(hwnd == NULL) {
  MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
  return 0;
 }

 while(GetMessage(&msg, NULL, 0, 0) > 0) {
  TranslateMessage(&msg);
  DispatchMessage(&msg);
 }
 return msg.wParam;
}