
Gui, Add, Text, x200 y10 w50 h20 vA, hi
Gui, Add, Edit, x20 y65 w40 h20 vcnt1, 1
Gui, Add, Edit, x80 y65 w40 h20 vcnt2, 1
Gui Show
vcnt1:=1
vcnt2:=1



FileSelectFile, path
Exc := ComObjActive("Excel.Application")
Exc.Workbooks.Open(path)
Exc.Visible :=true


Loop
{
	GUI, submit, nohide
	FormatTime, vt, m s,m분s초
	GuiControl, , A, %vt%
	Sleep, 1000
}


return





return
F1::
{
	GUI, submit, nohide
	FormatTime, vm,h m s,h:m:s:
	tmp := cnt1
	Exc.cells(tmp,3).value:=vm
	tmp := tmp + 1
	GuiControl, , cnt1, %tmp%
	vcnt1:=tmp
}



return

F2::
{
	GUI, submit, nohide
	FormatTime, vm,h m s,h:m:s
	tmp := cnt2
	Exc.cells(tmp,4).Value:=vm
	tmp := tmp + 1
	GuiControl, , cnt2, %tmp%
	vcnt:=tmp
}
return
	
	
