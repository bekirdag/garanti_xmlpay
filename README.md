garanti_xmlpay
==============

Garanti bank drupal commerce pay module

Change your info starting on line 260 in garanti_xmlpay.module

$strMode = "PROD";
$strVersion = "v0.01";
$strTerminalID = "100xxxxx";
$strTerminalID_ = "0100xxxxx"; //TerminalID başına 0 eklenerek 9 digite tamamlanmalÀùdÀùr.
$strProvUserID = "PROVAUT";
$strProvisionPassword = "xxx"; //ProvUserID şifresi
$strUserID = "xxx";
$strMerchantID = "xxx"; //Üye işyeri numarası
$strIPAddress = $nvp['x_customer_ip'];  //Müşteri IP si 
$strEmailAddress = "test@test.com";
