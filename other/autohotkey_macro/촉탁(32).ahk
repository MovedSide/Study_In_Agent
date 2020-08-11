; 테스트 파일
Coordmode, Mouse, Screen ; 스크린으로 화면 확장
Gui, Add, Text, x13 y35 w40 h20, index : 
Gui, Add, Edit, x60 y30 w50 h20 vcnt, 2
Gui, Add, Text, x13 y65 w50 h20, 날짜 : 
Gui, Add, Edit, x60 y65 w110 h20 vT2, 
Gui, Add, Text, x13 y95 w50 h20, 코드 : 
Gui, Add, Edit, x60 y90 w110 h20 vT3, 
Gui, Add, Text, x13 y125 w50 h20, 의사 : 
Gui, Add, Edit, x60 y120 w110 h20 vT4, 
Gui, Add, Text, x13 y155 w50 h20, 이름
Gui, Add, Edit, x60 y150 w110 h20 vT5, 
Gui, Add, Text, x13 y185 w50 h20, 생년월일
Gui, Add, Edit, x60 y180 w110 h20 vT6,
Gui, Add, Text, x13 y210 w50 h20 vT7, 
Gui, Add, Text, x20 y210 w50 h20 vT8, 
Gui, Add, Text, x20 y240 w200 h20 , z:날짜x:코드c:사유a:다음진료
Gui, Add, Checkbox, vC1, 가족
Gui, Add, Button, x20 y300 w110 h20, Exit
Gui Show

FileSelectFile, path
Exc := ComObjActive("Excel.Application")
Exc.Workbooks.Open(path)
Exc.Visible :=true

return

ButtonExit:
{

   ExitApp
}
return
F1::
{
   Hotkey,a,off
   Hotkey,z,off
   Hotkey,x,off
   Hotkey,c,off
}
return
F2::
{
   Hotkey,a,on
   Hotkey,z,on
   Hotkey,x,on
   Hotkey,c,on
}
return
z::
GUI, submit, nohide
send, %T2%
send {Tab}
send {Tab}
send {Enter}
return

x::
GUI, submit, nohide
send {Tab}
send, %T3%
send {Enter}
send {Enter}
send {Tab}
send {Tab}
if C1 = 1 ;체크 함
{
   send {down}
}
send {Tab}
send {Enter}
return
c::
GUI, submit, nohide
send {Tab}
send {Enter}

return

a::
GUI, submit, nohide
SetFormat,float,0
vindex1:= 1
vindex2:=6
vindex3:=3
vindex4:=4
vindex5:=5
vindex6:=10
vindex7:=12
vindex8:=8
tmp := cnt
vp1 := Exc.cells(tmp,vindex1).Value ; 날짜
vp2 := Exc.cells(tmp,vindex2).Value ; 코드
vp3 := Exc.cells(tmp,vindex3).Value ; 이름
vp4 := Exc.cells(tmp,vindex4).Value ; 생년월일
vp5 := Exc.cells(tmp,vindex5).Value ; 의사
vp6 := Exc.cells(tmp,vindex6).Value ; 진찰사유
vp7 := Exc.cells(tmp,vindex7).Value ; 진찰내용
vp8 := Exc.cells(tmp,vindex8).Value ; 진찰요청자
StringReplace,vp1,vp1,-,,All
GuiControl, , T2, %vp1%
GuiControl, , T3, %vp2%
GuiControl, , T4, %vp5%
GuiControl, , T5, %vp3%
GuiControl, , T6, %vp4%
GuiControl, , T7, %vp6%
GuiControl, , T8, %vp7%
IfInString,vp8,가족
{
   GuiControl,,C1,1
}
else
{
   GuiControl,,C1,0
}
tmp := tmp +1
GuiControl, , cnt , %tmp%
vcnt := tmp
return