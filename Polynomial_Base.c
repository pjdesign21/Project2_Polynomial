extern operator_t OpType(char op)
{
	op=='+'?return Add;
	op=='-'?return Minus;
	op=='*'?return Multiple:return Divide;
}
