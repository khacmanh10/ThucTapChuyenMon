Các bước cài đặt và build chương trình

Phần nạp code
B1: Download source code trên Github về
B2: Download Arduino IDE
B3: Mở IDE lên để cài đặt board ESP8266
B4: Vào file -> Preferences ở mục Additional boards manager URLs: nhập dòng này vào: http://arduino.esp8266.com/stable/package_esp8266com_index.json
B5: Vào Tools -> Board -> Boards Manager -> search "esp8266" và nhấn INSTALL để cài đặt 
B6: Chọn mục Search bên thanh công cụ bên trái search "Blynk" và nhấn INSTALL để cài đặt 
B7: Giải nén source code và chạy file Edgent_ESP8266_MQ5
B8: Tools -> Board -> esp8266 -> NodeMCU 1.0 (ESP-12 Module)
B9: Tools -> Port -> chọn COM tương ứng
	cách tìm COM:
		Mở Device Manager của Windows -> Ports (COM & LPT) xem dòng USB-SERIAL CH340 có COM là bao nhiêu.
B10: Click vào biểu tượng -> (Upload) để nạp code vào ESP8266
B11: Sau khi nạp xong Click vào Serial Moniter trên góc phải màn hình chọn tốc độ đọc là 115200 baud
B12: Nhấn giữ nút Flash trên Module 10s đến khi đèn xanh trên Module chớp liên tục thì hệ thống đã sẵn sàng kết nối


Phần kết nối với Blynk
	Trên Web
B1: Truy cập link: https://blynk.cloud/dashboard/login
B2: Đăng nhập bằng tài khoản sau (có phân biệt chữ hoa chữ thường)
	Email: 	  blynkiotk61@gmail.com
	Password: Thuctapchuyenmonk61
B3: Click vào biểu tượng kính lúp và tìm My Device "CAM BIEN KHI GAS"

	Trên smartphone
B1: Trên điện thoại tải app Blynk và đăng nhập bằng tài khoản trên
B2: Vào app nhấp vào dấu 3 chấm trên góc phải -> nhấp vào thêm một lần dấu 3 chấm nữa -> Reconfigure -> Start để bắt đầuu kết nối Wifi
(Lưu ý chỉ kết nối được với wifi có băng tần 2.4G)
Chú ý: Trường  hợp không kết nối được wifi của Module thì làm lại B12 của phần nạp code và làm lại B2 của phần Smartphone