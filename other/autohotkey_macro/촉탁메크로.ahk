; �׽�Ʈ ����
Coordmode, Mouse, Screen ; ��ũ������ ȭ�� Ȯ��
Gui, Add, Text, x13 y35 w40 h20, index : 
Gui, Add, Edit, x60 y30 w50 h20 vcnt, 2
Gui, Add, Text, x13 y65 w50 h20, ��¥ : 
Gui, Add, Edit, x60 y65 w110 h20 vT2, 
Gui, Add, Text, x13 y95 w50 h20, �ڵ� : 
Gui, Add, Edit, x60 y90 w110 h20 vT3, 
Gui, Add, Text, x13 y125 w50 h20, �ǻ� : 
Gui, Add, Edit, x60 y120 w110 h20 vT4, 
Gui, Add, Text, x13 y155 w50 h20, �̸�
Gui, Add, Edit, x60 y150 w110 h20 vT5, 
Gui, Add, Text, x13 y185 w50 h20, �������
Gui, Add, Edit, x60 y180 w110 h20 vT6,
Gui, Add, Text, x13 y210 w50 h20 vT7, 
Gui, Add, Text, x20 y210 w50 h20 vT8, 
Gui, Add, Text, x20 y240 w200 h20 , z:��¥x:�ڵ�c:����a:��������
Gui, Add, Checkbox, vC1, ����
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
if C1 = 1 ;üũ ��
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
vp1 := Exc.cells(tmp,vindex1).Value ; ��¥
vp2 := Exc.cells(tmp,vindex2).Value ; �ڵ�
vp3 := Exc.cells(tmp,vindex3).Value ; �̸�
vp4 := Exc.cells(tmp,vindex4).Value ; �������
vp5 := Exc.cells(tmp,vindex5).Value ; �ǻ�
vp6 := Exc.cells(tmp,vindex6).Value ; ��������
vp7 := Exc.cells(tmp,vindex7).Value ; ��������
vp8 := Exc.cells(tmp,vindex8).Value ; ������û��
StringReplace,vp1,vp1,-,,All
GuiControl, , T2, %vp1%
GuiControl, , T3, %vp2%
GuiControl, , T4, %vp5%
GuiControl, , T5, %vp3%
GuiControl, , T6, %vp4%
GuiControl, , T7, %vp6%
GuiControl, , T8, %vp7%
IfInString,vp8,����
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