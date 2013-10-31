public class MassiveNumbers
{
	public static String getLargest( String numberA, String numberB )
	{
		int b, A, c, D;
		String [] numA = numberA.split( "\\^" );
		String [] numB = numberB.split( "\\^" );
		A = Integer.parseInt( numA[0] );
		b = Integer.parseInt( numA[1] );
		c = Integer.parseInt( numB[0] );
		D = Integer.parseInt( numB[1] );

		if( b*Math.log(A) > D*Math.log(c) ) return numberA;
		else return numberB;
	}

	public static void main( String[] Args )
	{
		String a = "3^100";
		String b = "6^100";

		String s = getLargest( a, b );
		System.out.println( s );
	}
}
