#### vježba 8

Koristeći MFC napravite ovakav dijalog.

Add dodaje red u listu, Delete briše selektirani red.

![drawing](/screenshot.jpg?raw=true)

Uputstva:

* napravite pomoću AppWizard-a MFC aplikaciju,  Application type = "Dialog based"
* na dijalog stavite kontrole
* napravite pomoću ClassWizard-a DDX_Control na list kontrolu
* u OnInitDialog dodajte stupce u list kontrolu ([CListCtrl::InsertColumn](https://msdn.microsoft.com/en-us/library/wz5b6131.aspx))
* na "Add" dodajte novi red u list kontrolu: 
  * tekst iz edit kontrola možete uzeti sa [GetDlgItemText](https://msdn.microsoft.com/en-us/library/xcws9sbs.aspx)
  * CListCtrl::InsertItem dodaje red i postavlja tekst prvog stupca
  * CListCtrl::SetItemText postavlja tekst u ostale stupce
* na "Delete" obrišite odabrani red ([CListCtrl::DeleteItem](https://msdn.microsoft.com/en-us/library/84fyba4z.aspx))
* odabrani red možete saznati pomoću [CListCtrl::GetNextItem](https://msdn.microsoft.com/en-us/library/aa9fthz4.aspx) koristeći LVNI_SELECTED
* odabir cijelog reda se postiže ex-stilom LVS_EX_FULLROWSELECT ([CListCtrl::SetExtendedStyle](https://msdn.microsoft.com/en-us/library/c7ezbf7b.aspx))

