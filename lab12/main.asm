


; Replace with your application code
cli ; �������� ����������"
	; DDR"
	ldi r16, 1 << PB0 ; ������������ ��������� "0000 0001" � ����� r16"
	out DDRB, r16 ; ����������� � ������� r16 � I/O ������ DDRB"

	ldi r16, (1 << PC1) | (1 << PC2) ; ������������ ��������� "0000 0101" � ����� r16"
	out DDRC, r16 ; ����������� � ������� r16 � I/O ������ DDRC"

	ldi r16, (1 << PD3) | (1 << PD7) ; ������������ ��������� "0011 0000" � ����� r16"
	out DDRD, r16 ; ����������� � ������� r16 � I/O ������ DDRD"

	; PORT"
	ldi r16, 0b00010000 ; ������������ ��������� "0001 0000" � ����� r16"
	out PORTB, r16 ; ����������� � ������� r16 � I/O ������ PORTB"

	ldi r16, 0b00010001; ������������ ��������� "0001 0001" � ����� r16"
	out PORTC, r16 ; ����������� � ������� r16 � I/O ������ PORTC"

	ldi r16, 0b01000100 ; ������������ ��������� "0100 0100" � ����� r16"
	out PORTD, r16 ; ����������� � ������� r16 � I/O ������ PORTD"

	sei ; ����� ����������"

start:
	cli ; �������� ����������"
	; �� Arduino Uno �������� �� pin 13, � ������ �� pin 12"
	in r16, PINB ; ����������� � I/O ������� PINB � ������ r16"
	sbrc r16, PB4 ; ���������� �������� �������, ���� 4� �� � ������ r16 ������ (������� 0)"
	cbi PORTB, PB0 ; ������������ 5�� ��� � I/O ������ PORTB � 0"
	nop ; ���� �������� �������, ���������� ���� (��� ������ �� ����������)"
	sbrs r16, PB4 ; ���������� �������� �������, ���� 4� �� � ������ r16 ���������� (������� 1)"
	sbi PORTB, PB0 ; �������� 5�� ��� � I/O ������ PORTB � 1"
	nop ; ���� �������� �������, ���������� ���� (��� ������ �� ����������)"

	; �� Arduino Uno �������� �� A1, � ������ �� A0"
	in r16, PINC ; ����������� � I/O ������� PINC � ������ r16"
	sbrc r16, PC0 ; ���������� �������� �������, ���� 0� �� � ������ r16 ������ (������� 0)"
	cbi PORTC, PC1 ; ������������ 1�� ��� � I/O ������ PORTC � 0"
	nop ; ���� �������� �������, ���������� ���� (��� ������ �� ����������)"
	sbrs r16, PC0 ; ���������� �������� �������, ���� 0� �� � ������ r16 ���������� (������� 1)"
	sbi PORTC, PC1 ; �������� 1�� ��� � I/O ������ PORTC � 1"
	nop ; ���� �������� �������, ���������� ���� (��� ������ �� ����������)"

	; �� Arduino Uno �������� �� A5, � ������ �� A4"
	in r16, PINC ; ����������� � I/O ������� PINC � ������ r16"
	sbrc r16, PC4 ; ���������� �������� �������, ���� 4� �� � ������ r16 ������ (������� 0)"
	cbi PORTC, PC2 ; ������������ 5�� ��� � I/O ������ PORTC � 0"
	nop ; ���� �������� �������, ���������� ���� (��� ������ �� ����������)"
	sbrs r16, PC4 ; ���������� �������� �������, ���� 4� �� � ������ r16 ���������� (������� 1)"
	sbi PORTC, PC2 ; �������� 5�� ��� � I/O ������ PORTC � 1"
	nop ; ���� �������� �������, ���������� ���� (��� ������ �� ����������)"

	; �� Arduino Uno �������� �� pin 3, � ������ �� pin 2"
	in r16, PIND ; ����������� � I/O ������� PIND � ������ r16"
	sbrc r16, PD2 ; ���������� �������� �������, ���� 2� �� � ������ r16 ������ (������� 0)"
	cbi PORTD, PD3 ; ������������ 3�� ��� � I/O ������ PORTD � 1"
	nop ; ���� �������� �������, ���������� ���� (��� ������ �� ����������)"
	sbrs r16, PD2 ; ���������� �������� �������, ���� 2� �� � ������ r16 ���������� (������� 1)"
	sbi PORTD, PD3 ; �������� 3�� ��� � I/O ������ PORTD � 0"
	nop ; ���� �������� �������, ���������� ���� (��� ������ �� ����������)"

	; �� Arduino Uno �������� �� pin 7, � ������ �� pin 6"
	in r16, PIND ; ����������� � I/O ������� PIND � ������ r16"
	sbrc r16, PD6 ; ���������� �������� �������, ���� 6� �� � ������ r16 ������ (������� 0)"
	cbi PORTD, PD7 ; ������������ 7�� ��� � I/O ������ PORTD � 1"
	nop ; ���� �������� �������, ���������� ���� (��� ������ �� ����������)"
	sbrs r16, PD6 ; ���������� �������� �������, ���� 6� �� � ������ r16 ���������� (������� 1)"
	sbi PORTD, PD7 ; �������� 7�� ��� � I/O ������ PORTD � 0"
	nop ; ���� �������� �������, ���������� ���� (��� ������ �� ����������)"

	sei ; ����� ����������"
	rjmp start
