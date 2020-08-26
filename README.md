# Đề cương: 
## Các chiến lược thiết kế thuật toán :
  
## Chia để trị: 

Chia vấn đề thành các vấn đề con cùng dạng với vấn đề đã cho, chỉ khác là kích thước nhỏ hơn. -> là kĩ thuật top-down, tính nghiệm các vấn đề con từ lớn tới nhỏ
Mỗi vấn đề con được giải quyết độc lập, sau đó ta kết hợp nghiệm lời của các vấn đề con để nhận được nghiệm cho vấn đề đã cho.
Nếu vấn đề con đủ nhỏ có thể dễ dàng tính được nghiệm, thì ta tiến hành giải quyết. Nếu không ta áp dụng đệ quy thủ tục ở trên 
 
## Đệ quy:

là 1 thuật toán chia để trị, được biểu diễn các hàm đệ quy có lời gọi hàm đền chính nó.
  
Giải thuật đệ quy cho một vấn đề cần phải thoả mãn các đòi hỏi sau: 
1. Chứa lời giải cho các trường hợp đơn giản nhất của vấn đề. Các
trường hợp này được gọi là các trường hợp cơ sở hay các
trường hợp dừng.
2. Chứa các lời gọi đệ quy giải quyết các vấn đề con với cỡ nhỏ
hơn.
3. Các lời gọi đệ quy sinh ra các lời gọi đệ quy khác và về tiềm
năng các lời gọi đệ quy phải dẫn tới các trường hợp cơ sở.

### Ưu điểm:
      đối với 1 số bài toán cụ thể, đệ quy rõ ràng hơn đối với duyệt tuần tự
### Nhược điểm: 
      1, Mỗi lần gọi hàm đề quy, hệ thống sẽ tạo 1 **bản ghi** trong **ngăn xếp thời gian chạy**, và một bản ghi chỉ có thể bị hủy nếu các bản ghi được tạo sau nó bị hủy 
      -> đòi hỏi nhiều không gian trong ngăn xếp thời gian chạy, thậm chí có thể vượt quá khả năng ngăn xếp thời gian chạy trong máy tính 
      2, Lời gọi để quy có thể dẫn tới tính nghiệm của bài toán con nhiều lần 
      -> tốn nhiều thời gian nếu không được tối ưu hóa hợp lí :<
## Quy hoạch động

là kĩ thuật chia nhỏ bài toán , bottom-up, tính nghiệm các bài toán từ nhỏ đến lớn và ghi lại kết quả đã tính được, thực hiện bằng duyệt tuần tự

### Chiến lược thực hiện:
    1, đưa ra cách tính nghiệm bài toán con đơn giản nhất
    2, tìm ra công thức, quy luật xây dựng nghiệm của bài toán thông qua các bài toán con
    3, thiết kế bảng lưu nghiệm bài toán
    4, tính nghiệm các bài toán từ nhỏ đến lớn, lưu vào mảng
    5, xây dựng nghiệm của bài toán từ mảng
## Quay lui: // các thuật này không được cô dạy, nếu muốn biết thì cứ đọc thôi :3
### vét cạn:

    xem xét tất cả các ứng viên để tìm ra đối tượng mong muốn
    Ý tưởng: sinh ra tất cả các khả năng, kiểm tra xem các khả năng có thỏa mãn điều kiện bài toán hay không.
    Khá tốn thời gian và kém hiệu quả
    
### Quay lui: đúng vậy, lại quay lui :)
    
    /// cái này nó nói trừu tượng vcl, chắc là không vào đâu :3
    
    Quay lui có ý tưởng giống với vét cạn, nhưng tối ưu hơi. Khi xây dựng 1 trạng thái mới, ta sẽ xem trạng thái đó có thỏa mãn các điều kiện cho trước hay không. Nếu có, trạng thái đó được giữ lại để tiếp tục xây dựng nghiệm
    còn không thì sẽ bị loại bỏ 
    
    **Thuật toán nhánh và cận:** bài toán: tìm 1 nghiệm có dạng 1 vector a1...an, mỗi nghiệm được gắn cho 1 cost.
    gọi (a1...a_k-1) là nghiệm 1 phần, (a1...a_k) là nghiệm mở rộng (k <= n), và cost(a1...a_k-1) < cost(a1...a_k) với mọi k
    nếu nghiệm mở rộng không tốt bằng nghiệm tốt nhất, ta sẽ không xét nghiệm mở rộng đó. 
    nếu cost nghiệm 1 phần > cost nghiệm tốt nhất, ta sẽ không xét nghiệm 1 phần đó (page 416)
### Tham ăn:
    tại mỗi bước, ta sẽ lựa chọn quyết định để thực hiện là quyết định được xem là tốt nhất trong 1 ngữ cảnh nào đó được xác định bởi bài toán. quyết định được lựa chọn là quyết định tối ưu địa phương.
    tùy vào bài toán mà ta đưa ra tiêu chuẩn lựa chọn thích hợp
    
### Ngẫu nhiên: 
    random :3
    
    

