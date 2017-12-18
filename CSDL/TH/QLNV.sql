use QLNV
create table NHANVIEN
(
	MANV int primary key,
	TENNV varchar(30),
	MAVT int,
	MAPB int,
	LUONG int,
	NGAYVL smalldatetime
)

create table PHONGBAN
(
	MAPB int primary key,
	TENPB char(10),
	DIACHI varchar(40),
	NGAYTL smalldatetime,
	MANV int foreign key references NHANVIEN(MANV)
)

create table VITRI
(
	MAVT int primary key,
	MOTA varchar(30)
)

create table MUCLUONG
(
	MAML int primary key,
	MUCTHAP int,
	MUCCAO int
)