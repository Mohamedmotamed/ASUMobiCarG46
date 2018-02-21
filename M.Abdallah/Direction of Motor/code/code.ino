 /* انا هنا بالكود دا واخد مخرجين من 
الاردوينو  ومخليهم خرج وموصل ماتور باربعة ترانزستور 
مشغلهم كسويتشات وواخد كل اتنين مع بعض ع مخرج 
وبخلي مرة احد المخرجين بخمسة والتاني بصفر فبيدور 
الماتور ف اتجاه بعدين بعد ثانيتين بعمل العكس 
فيدور فالاتجاه التاني
لاني بكدا بعكس البولارتي بتاعت الجهد ع الاتور*/
int dir1 = 13; 
int dir2 = 10 ;
void setup ()
{
  pinMode (dir1,OUTPUT);
  pinMode (dir2,OUTPUT);
}
void loop ()
{
  digitalWrite (dir1,HIGH);
  digitalWrite (dir2,LOW);
  delay(2000);
  digitalWrite (dir1,LOW);
  digitalWrite (dir2,HIGH);
  delay(2000);
  
}

