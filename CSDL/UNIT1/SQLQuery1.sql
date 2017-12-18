


create	table 	KHACHHANG
(	MAKH 	char(4) primary key,
	HOTEN	varchar(40),
	DCHI	varchar(50),
	SODT 	varchar(20),
	NGSINH	datetime,
	NGDK	datetime,
	DOANHSO	money
)

create 	table 	NHANVIEN
(	MANV	char(4) primary key,
	HOTEN	varchar(40),
	SODT	varchar(20),
	NGVL	datetime
)

create	table 	SANPHAM
(	MASP	char(4) primary key,
	TENSP	varchar(40),
	DVT	varchar(20),
	NUOCSX	varchar(40),
	GIA	money
)

create 	table	HOADON
(	SOHD	int primary key, 
	NGHD	datetime, 
	MAKH	char(4) references KHACHHANG(MAKH),
	MANV	char(4) references NHANVIEN(MANV),
	TRIGIA	money
)

create	table	CTHD
(	SOHD	int references HOADON(SOHD),
	MASP	char(4) references SANPHAM(MASP),
	SL	int
)



insert into KHACHHANG values ('KH01','Nguyen Van A','731, Tran Hung Dao, Q 5, Tp HCM','08823451','10/22/1960','10/22/2006',13000000)
insert into KHACHHANG values ('KH02','Tran Ngoc Han','23/5, Nguyen Trai, Q 5, Tp HCM','0908256478','04/03/1974','07/30/2006',280000)
insert into KHACHHANG values ('KH03','Tran Ngoc Linh','45, Nguyen Canh Chan, Q 1, Tp HCM','0938776266','06/12/1980','08/05/2006',3860000)
insert into KHACHHANG values ('KH04','Tran Minh Long','50/34 Le Dai Hanh, Q 10, Tp HCM','0917325476','03/09/1965','10/02/2006',250000)
insert into KHACHHANG values ('KH05','Le Nhat Minh','34, Truong Dinh, Q 3, Tp HCM','08246108','03/10/1950','10/28/2006',21000)
insert into KHACHHANG values ('KH06','Le Hoai Thuong','227, Nguyen Van Cu, Q 5, Tp HCM','08631738','12/31/1981','11/24/2006',915000)
insert into KHACHHANG values ('KH07','Nguyen Van Tam','32/3, Tran Binh Trong, Q 5, Tp HCM','0916783565','04/06/1971','12/01/2006',12500)
insert into KHACHHANG values ('KH08','Phan Thi Thanh','45/2, An Duong Vuong, Q 5, Tp HCM','0938435756','01/10/1971','12/13/2006',365000)
insert into KHACHHANG values ('KH09','Le Ha Vinh','873, Le Hong Phong, Q 5, Tp HCM','08654763','09/03/1979','01/14/2007',70000)
insert into KHACHHANG values ('KH10','Ha Duy Lap','34/34B, Nguyen Trai, Q 1, Tp HCM','08768904','05/02/1983','01/16/2007',67500)	

insert into NHANVIEN values ('NV01','Nguyen Nhu Nhut','0927345678','04/13/2006')
insert into NHANVIEN values ('NV02','Le Thi Phi Yen','0987567390','04/21/2006')
insert into NHANVIEN values ('NV03','Nguyen Van B','0997047382','04/27/2006')
insert into NHANVIEN values ('NV04','Ngo Thanh Tuan','0913758498','06/24/2006')
insert into NHANVIEN values ('NV05','Nguyen Thi Truc Thanh','0918590387','07/20/2006')

insert into SANPHAM values ('BC01','But chi','cay','Singapore',3000)
insert into SANPHAM values ('BC02','But chi','cay','Singapore',5000)
insert into SANPHAM values ('BC03','But chi','cay','Viet Nam',3500)
insert into SANPHAM values ('BC04','But chi','hop','Viet Nam',30000)
insert into SANPHAM values ('BB01','But bi','cay','Viet Nam',5000)
insert into SANPHAM values ('BB02','But bi','cay','Trung Quoc',7000)
insert into SANPHAM values ('BB03','But bi','hop','Thai Lan',100000)
insert into SANPHAM values ('TV01','Tap 100 giay mong','quyen','Trung Quoc',2500)
insert into SANPHAM values ('TV02','Tap 200 giay mong','quyen','Trung Quoc',4500)
insert into SANPHAM values ('TV03','Tap 100 giay tot','quyen','Viet Nam',3000)
insert into SANPHAM values ('TV04','Tap 200 giay tot','quyen','Viet Nam',5500)
insert into SANPHAM values ('TV05','Tap 100 trang','chuc','Viet Nam',23000)
insert into SANPHAM values ('TV06','Tap 200 trang','chuc','Viet Nam',53000)
insert into SANPHAM values ('TV07','Tap 100 trang','chuc','Trung Quoc',34000)
insert into SANPHAM values ('ST01','So tay 500 trang','quyen','Trung Quoc',40000)
insert into SANPHAM values ('ST02','So tay loai 1','quyen','Viet Nam',55000)
insert into SANPHAM values ('ST03','So tay loai 2','quyen','Viet Nam',51000)
insert into SANPHAM values ('ST04','So tay ','quyen','Thai Lan',55000)
insert into SANPHAM values ('ST05','So tay mong','quyen','Thai Lan',20000)
insert into SANPHAM values ('ST06','Phan viet bang','hop','Viet Nam',5000)
insert into SANPHAM values ('ST07','Phan khong bui','hop','Viet Nam',7000)
insert into SANPHAM values ('ST08','Bong bang','cai','Viet Nam',1000)
insert into SANPHAM values ('ST09','But long','cay','Viet Nam',5000)
insert into SANPHAM values ('ST10','But long','cay','Trung Quoc',7000)

insert into HOADON values (1001,'7/23/2006','KH01','NV01',320000)
insert into HOADON values (1002,'8/12/2006','KH01','NV02',840000)
insert into HOADON values (1003,'8/23/2006','KH02','NV01',100000)
insert into HOADON values (1004,'9/1/2006','KH02','NV01',180000)
insert into HOADON values (1005,'10/20/2006','KH01','NV02',3800000)
insert into HOADON values (1006,'10/16/2006','KH01','NV03',2430000)
insert into HOADON values (1007,'10/28/2006','KH03','NV03',510000)
insert into HOADON values (1008,'10/28/2006','KH01','NV03',440000)
insert into HOADON values (1009,'10/28/2006','KH03','NV04',200000)
insert into HOADON values (1010,'11/1/2006','KH01','NV01',5200000)
insert into HOADON values (1011,'11/4/2006','KH04','NV03',250000)
insert into HOADON values (1012,'11/30/2006','KH05','NV03',21000)
insert into HOADON values (1013,'12/12/2006','KH06','NV01',5000)
insert into HOADON values (1014,'12/31/2006','KH03','NV02',3150000)
insert into HOADON values (1015,'1/1/2007','KH06','NV01',910000)
insert into HOADON values (1016,'1/1/2007','KH07','NV02',12500)
insert into HOADON values (1017,'1/2/2007','KH08','NV03',35000)
insert into HOADON values (1018,'1/13/2007','KH08','NV03',330000)
insert into HOADON values (1019,'1/13/2007','KH01','NV03',30000)
insert into HOADON values (1020,'1/14/2007','KH09','NV04',70000)
insert into HOADON values (1021,'1/16/2007','KH10','NV03',67500)
insert into HOADON values (1022,'1/16/2007',null,'NV03',7000)
insert into HOADON values (1023,'1/17/2007',null,'NV01',330000)

insert into CTHD values (1001,'TV02',10)
insert into CTHD values (1001,'ST01',5)
insert into CTHD values (1001,'BC01',5)
insert into CTHD values (1001,'BC02',10)
insert into CTHD values (1001,'ST08',10)
insert into CTHD values (1002,'BC04',20)
insert into CTHD values (1002,'BB01',20)
insert into CTHD values (1002,'BB02',20)
insert into CTHD values (1003,'BB03',10)
insert into CTHD values (1004,'TV01',20)
insert into CTHD values (1004,'TV02',20)
insert into CTHD values (1004,'TV03',20)
insert into CTHD values (1004,'TV04',20)
insert into CTHD values (1005,'TV05',50)
insert into CTHD values (1005,'TV06',50)
insert into CTHD values (1006,'TV07',20)
insert into CTHD values (1006,'ST01',30)
insert into CTHD values (1006,'ST02',10)
insert into CTHD values (1007,'ST03',10)
insert into CTHD values (1008,'ST04',8)
insert into CTHD values (1009,'ST05',10)
insert into CTHD values (1010,'TV07',50)
insert into CTHD values (1010,'ST07',50)
insert into CTHD values (1010,'ST08',100)
insert into CTHD values (1010,'ST04',50)
insert into CTHD values (1010,'TV03',100)
insert into CTHD values (1011,'ST06',50)
insert into CTHD values (1012,'ST07',3)
insert into CTHD values (1013,'ST08',5)
insert into CTHD values (1014,'BC02',80)
insert into CTHD values (1014,'BB02',100)
insert into CTHD values (1014,'BC04',60)
insert into CTHD values (1014,'BB01',50)
insert into CTHD values (1015,'BB02',30)
insert into CTHD values (1015,'BB03',7)
insert into CTHD values (1016,'TV01',5)
insert into CTHD values (1017,'TV02',1)
insert into CTHD values (1017,'TV03',1)
insert into CTHD values (1017,'TV04',5)
insert into CTHD values (1018,'ST04',6)
insert into CTHD values (1019,'ST05',1)
insert into CTHD values (1019,'ST06',2)
insert into CTHD values (1020,'ST07',10)
insert into CTHD values (1021,'ST08',5)
insert into CTHD values (1021,'TV01',7)
insert into CTHD values (1021,'TV02',10)
insert into CTHD values (1022,'ST07',1)
insert into CTHD values (1023,'ST04',6)
----------------------------------------------------------------
--1: In ra danh sách các sản phẩm (MASP,TENSP) do “Trung Quoc” sản xuất.
select MASP,TENSP from SANPHAM where NUOCSX = 'Trung Quoc'
--2: In ra danh sách các sản phẩm (MASP, TENSP) có đơn vị tính là “cay”, ”quyen”.
select MASP, TENSP from SANPHAM where DVT = 'cay' or DVT = 'quyen'
--3: In ra danh sách các sản phẩm (MASP,TENSP) có mã sản phẩm bắt đầu là “B” và kết thúc là “01”.
select MASP, TENSP from SANPHAM where MASP like 'B%01'
--4: In ra danh sách các sản phẩm (MASP,TENSP) do “Trung Quốc” sản xuất có giá từ 30.000 đế 40.000.
select MASP, TENSP from SANPHAM where NUOCSX = 'Trung Quoc' and GIA between 30000 and 40000
--5: In ra danh sách các sản phẩm (MASP,TENSP) do “Trung Quoc” hoặc “Thai Lan” sản xuất có giá từ 30.000 đến 40.000.
select MASP,TENSP from SANPHAM where (NUOCSX = 'Trung Quoc' or NUOCSX = 'Thai Lan') and (GIA between 30000 and 40000)
--6: In ra các số hóa đơn, trị giá hóa đơn bán ra trong ngày 1/1/2007 và ngày 2/1/2007
select SOHD,TRIGIA from HOADON where NGHD = '1/1/2007' or NGHD = '1/2/2007'
--7: In ra các số hóa đơn, trị giá hóa đơn trong tháng 1/2007, sắp xếp theo ngày (tăng dần) và trị giá của hóa đơn (giảm dần).
select SOHD, TRIGIA from HOADON where month(NGHD) = 1 and year(NGHD) = 2007 order by NGHD ASC, TRIGIA DESC
--8: In ra danh sách các khách hàng (MAKH, HOTEN) đã mua hàng trong ngày 1/1/2007
select KHACHHANG.MAKH, KHACHHANG.HOTEN from KHACHHANG inner join HOADON on KHACHHANG.MAKH = HOADON.MAKH where NGHD = '1/1/2007'
--9: In ra số hóa đơn, trị giá các hóa đơn do nhân viên có tên “Nguyen Van B” lập trong ngày 28/10/2006.
select H.SOHD,H.TRIGIA from HOADON H inner join NHANVIEN  N on H.MANV = N.MANV where HOTEN = 'Nguyen Van B' and NGHD = '10/28/2006'
--10: In ra danh sách các sản phẩm (MASP,TENSP) được khách hàng có tên “Nguyen Van A” mua trong tháng 10/2006. 


--11: Tìm các số hóa đơn đã mua sản phẩm có mã số “BB01” hoặc “BB02”
select SOHD from CTHD where MASP in ('BB01','BB02')
--12: Tìm các số hóa đơn đã mua sản phẩm có mã số “BB01” hoặc “BB02”, mỗi sản phẩm mua với số lượng từ 10 đến 20
select SOHD from CTHD where MASP in('BB01','BB02') and SL between 10 and 20 
--13: Tìm các số hóa đơn mua cùng lúc 2 sản phẩm có mã số “BB01” và “BB02”, mỗi sản phẩm mua với số lượng từ 10 đến 20
select SOHD from CTHD A where A.MASP = 'BB01' and SL between 10 and 20 and 
	exists (select * from CTHD B where B.MASP = 'BB02' and SL between 10 and 20 and A.SOHD = B.SOHD)
--Cach dung in:
select SOHD from CTHD where MASP = 'BB01' and SL between 10 and 20 and 
	SOHD in( select SOHD from CTHD where MASP = 'BB02' and SL between 10 and 20)

--14: In ra danh sách các sản phẩm (MASP,TENSP) do “Trung Quoc” sản xuất hoặc các sản phẩm được bán ra trong ngày 1/1/2007.
select MASP, TENSP from SANPHAM where NUOCSX = 'Trung Quoc'
union
select SANPHAM.MASP,TENSP from SANPHAM, HOADON,CTHD where NGHD = '1/1/2007' and SANPHAM.MASP = CTHD.MASP and HOADON.SOHD = CTHD.SOHD
--15: In ra danh sách các sản phẩm (MASP,TENSP) không bán được
select MASP, TENSP from SANPHAM where MASP not in (select MASP from CTHD where SL != '0')
--hoac:
select MASP, TENSP from SANPHAM where not exists (select * from CTHD where CTHD.MASP = SANPHAM.MASP)
--16:In ra danh sách các sản phẩm (MASP,TENSP) không bán được trong năm 2006
select MASP, TENSP from SANPHAM where 
not exists (select * from CTHD inner join HOADON on HOADON.SOHD = CTHD.SOHD where year (NGHD) = 2006 and CTHD.MASP = SANPHAM.MASP)
--17: In ra danh sách các sản phẩm (MASP,TENSP) do “Trung Quoc” sản xuất không bán được trong năm 2006.
select MASP, TENSP from SANPHAM where NUOCSX = 'Trung Quoc' and
 not exists (select * from CTHD, HOADON where year(NGHD) = 2006 and CTHD.MASP = SANPHAM.MASP)
--18: Tìm số hóa đơn đã mua tất cả các sản phẩm do Singapore sản xuất
select SOHD from HOADON  where 
	not exists (select * from SANPHAM where NUOCSX = 'Singapore' 
		and not exists(select * from CTHD where  SANPHAM.MASP = CTHD.MASP and CTHD.SOHD = HOADON.SOHD))
--19: Tìm số hóa đơn trong năm 2006 đã mua ít nhất tất cả các sản phẩm do Singapore sản xuất.
SELECT H.SOHD 
FROM HOADON H
WHERE YEAR(NGHD) = 2006 AND NOT EXISTS(SELECT *
FROM SANPHAM S
WHERE NUOCSX = 'SINGAPORE'
AND NOT EXISTS(SELECT * 
FROM CTHD C
WHERE C.SOHD = H.SOHD
AND C.MASP = S.MASP))
--20: Có bao nhiêu hóa đơn không phải của khách hàng đăng ký thành viên mua?
select count(*) as SoHD_khong_phai_ from HOADON where MAKH not in(select MAKH from KHACHHANG where HOADON.MAKH = KHACHHANG.MAKH)
--21: Có bao nhiêu sản phẩm khác nhau được bán ra trong năm 2006.
select count(distinct MASP) as SôSP from CTHD,HOADON where year(NGHD)=2006 and CTHD.SOHD = HOADON.SOHD
--22: Cho biết trị giá hóa đơn cao nhất, thấp nhất là bao nhiêu ?
select max(TRIGIA) as TRIGIAmax,min(TRIGIA) as TRIGIAmin from HOADON
--23: Trị giá trung bình của tất cả các hóa đơn được bán ra trong năm 2006 là bao nhiêu?
select AVG(TRIGIA) as TB from HOADON, CTHD where year(NGHD) = 2006 
--24: Tính doanh thu bán hàng trong năm 2006
select sum(TRIGIA) as DoanhThu from HOADON, CTHD where year(NGHD) = 2006
--25: Tìm số hóa đơn có trị giá cao nhất trong năm 2006
select distinct SOHD from HOADON where year(NGHD) = 2006 and TRIGIA = (select max(TRIGIA) from HOADON where year(NGHD) = 2006)
--26: Tìm họ tên khách hàng đã mua hóa đơn có trị giá cao nhất trong năm 2006.
select distinct HOTEN from KHACHHANG,HOADON
 where year(NGHD) = 2006 and TRIGIA = (select max(TRIGIA) from HOADON where year(NGHD) = 2006) and KHACHHANG.MAKH = HOADON.MAKH
--27: In ra danh sách 3 khách hàng (MAKH, HOTEN) có doanh số cao nhất.
select top 3 MAKH,HOTEN from KHACHHANG order by DOANHSO DESC
--28: In ra danh sách các sản phẩm (MASP, TENSP) có giá bán bằng 1 trong 3 mức giá cao nhất
select MASP, TENSP from SANPHAM where GIA in(select distinct top 3 GIA from SANPHAM order by GIA DESC)
--29: In ra danh sách các sản phẩm (MASP, TENSP) do “Thai Lan” sản xuất có giá bằng 1 trong 3 mức giá cao nhất (của tất cả các sản phẩm).
select MASP, TENSP from SANPHAM where NUOCSX = 'Thai Lan' and GIA in(select distinct top 3 GIA from SANPHAM order by GIA DESC)
-- 30: In ra danh sách các sản phẩm (MASP, TENSP) do “Trung Quoc” sản xuất có giá bằng 1 trong 3 mức giá cao nhất (của sản phẩm do “Trung Quoc” sản xuất)
select MASP, TENSP from SANPHAM where NUOCSX = 'Trung Quoc' and GIA in(select distinct top 3 GIA from SANPHAM  where NUOCSX = 'Trung Quoc'  order by GIA DESC )
--31: * In ra danh sách 3 khách hàng có doanh số cao nhất (sắp xếp theo kiểu xếp hạng)
select top 3 MAKH,HOTEN from KHACHHANG order by DOANHSO DESC
--32: Tính tổng số sản phẩm do “Trung Quoc” sản xuất.
select distinct count(MASP) as 'Số SP do TQ sx' from SANPHAM where NUOCSX = 'Trung Quoc'
--33: Tính tổng số sản phẩm của từng nước sản xuất.
select distinct count(MASP) as 'Tổng số sp' from SANPHAM group by NUOCSX
--34: Với từng nước sản xuất, tìm giá bán cao nhất, thấp nhất, trung bình của các sản phẩm.
select max(GIA) as GIAMax, min(GIA) as GIAMin, AVG(GIA) as GIATB from SANPHAM group by NUOCSX
--35: Tính doanh thu bán hàng mỗi ngày.
select NGHD, sum(TRIGIA) as 'Doanh Thu' from HOADON group by NGHD
--36: Tính tổng số lần của từng sản phẩm bán ra trong tháng 10/2006
select distinct MASP, TENSP, count(MASP) from SANPHAM where MASP 
in(select MASP from HOADON, CTHD where month(NGHD) = 10 and year(NGHD) = 2006 and HOADON.SOHD = CTHD.SOHD) group by MASP, TENSP
--Tính tổng số lượng của từng sản phẩm bán ra trong tháng 10/2006
select MASP, sum(SL) from HOADON, CTHD where month(NGHD) = 10 and year(NGHD) = 2006 and HOADON.SOHD = CTHD.SOHD group by MASP
--37: Tính doanh thu bán hàng của từng tháng trong năm 2006.
select month(NGHD), SUM(TRIGIA) from HOADON where year(NGHD) = 2006 group by MONTH(NGHD) 
--38: Tìm hóa đơn có mua ít nhất 4 sản phẩm khác nhau
select SOHD from CTHD group by SOHD having count( MASP) >= 4
--39: Tìm hóa đơn có mua 3 sản phẩm do “Viet Nam” sản xuất (3 sản phẩm khác nhau)
select CTHD.SOHD from CTHD, SANPHAM where NUOCSX = 'Viet Nam' and CTHD.MASP = SANPHAM .MASP group by CTHD.SOHD having count(CTHD.MASP) = 3
--40: Tìm khách hàng (MAKH, HOTEN) có số lần mua hàng nhiều nhất.
select MAKH, HOTEN from KHACHHANG where MAKH = (select TOP 1 MAKH from HOADON group by MAKH order by count(SOHD) desc)
-- group by -> gom lại từng thằng KH, mỗi KH có nhiều món hàng -> Sắp xếp giảm;  với mỗi KH đếm xem thằng nào nheều món nhất -> chọn Top 1=> chọn MAKH, HOTEN cua cái thằng KH mua nhiều hàng nhất.
--41: Tháng mấy trong năm 2006, doanh số bán hàng cao nhất ?
select top 1 month(NGHD) as 'Tháng doanh thu cao nhất'  from HOADON where year(NGHD) = 2006 group by month(NGHD) order by SUM(TRIGIA) DESC
--42: Tìm sản phẩm (MASP, TENSP) có tổng số lượng bán ra thấp nhất trong năm 2006
select  MASP, TENSP from SANPHAM  where MASP  =  