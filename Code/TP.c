  /**--------------------------------------------------------**/
  /**       C o n v e r s i o n   Z vers C (Standard)        **/
  /**             Réalisée par Pr D.E ZEGOUR                 **/
  /**             E S I - Alger                              **/
  /**             Copywrite 2014                             **/
  /**--------------------------------------------------------**/

  #include <stdio.h>
  #include <stdlib.h>
  #include <Time.h>
  #include <math.h>

  typedef int bool ;

  #define True 1
  #define False 0

  /** Implémentation **\: ARBRE BINAIRE DE ENTIERS**/

  /** Arbres de recherche binaire **/

  typedef int Typeelem_Ai   ;
  typedef struct Noeud_Ai * Pointeur_Ai ;

  struct Noeud_Ai
    {
      Typeelem_Ai  Val ;
      Pointeur_Ai Fg ;
      Pointeur_Ai Fd ;
      Pointeur_Ai Pere ;
     } ;

  Typeelem_Ai Info_Ai( Pointeur_Ai P )
    { return P->Val;   }

  Pointeur_Ai Fg_Ai( Pointeur_Ai P)
    { return P->Fg ; }

  Pointeur_Ai Fd_Ai( Pointeur_Ai P)
    { return P->Fd ; }

  Pointeur_Ai Pere_Ai( Pointeur_Ai P)
    { return P->Pere ; }

  void Aff_info_Ai ( Pointeur_Ai P, Typeelem_Ai Val)
    {
       P->Val = Val ;
    }

  void Aff_fg_Ai( Pointeur_Ai P, Pointeur_Ai Q)
    { P->Fg =  Q;  }

  void Aff_fd_Ai( Pointeur_Ai P, Pointeur_Ai Q)
    { P->Fd =  Q ; }

  void Aff_pere_Ai( Pointeur_Ai P, Pointeur_Ai Q)
    { P->Pere =  Q ; }

  void Creernoeud_Ai( Pointeur_Ai *P)
    {
      *P = (struct Noeud_Ai *) malloc( sizeof( struct Noeud_Ai))   ;
      (*P)->Fg = NULL;
      (*P)->Fd = NULL;
      (*P)->Pere = NULL;
    }

  void Liberernoeud_Ai( Pointeur_Ai P)
    { free( P ) ; }

   
  /** Variables du programme principal **/
  Pointeur_Ai A1=NULL;
  Pointeur_Ai A2=NULL;
  Pointeur_Ai A3=NULL;
  Pointeur_Ai P=NULL;
  Pointeur_Ai Q=NULL;
  int I;
  int M;
  int N;
  bool L;
  int _Px1;
  int _Px2;
  int _Px3;
  int _Px4;
  int _Px5;

  /** Fonctions standards **/

  int Aleanombre( int N )
    { return ( rand() % N ); }

  int Min (int a, int b)
    {
      if (a < b) return(a);
      else return(b);
    }

  int Max (int a, int b)
    {
      if (a > b) return(a);
      else return(b);
    }

  /** Prototypes des fonctions **/

  bool  Creerarb_sansdouble (Pointeur_Ai *A , int *Nombre) ;
  bool  Inserer_sans_double (Pointeur_Ai *A , int *Val) ;
  void Inserer_avec_double (Pointeur_Ai *A , int *Val);
  bool  Verifier_bst (Pointeur_Ai *A , int *Min_val , int *Max_val) ;
  int  Nombre_noeud (Pointeur_Ai *P) ;
  bool  Verifier_fusion (Pointeur_Ai *P , int *N) ;
  void Supprimer_arb (Pointeur_Ai *P);
  Pointeur_Ai Suivant_inordre (Pointeur_Ai *P) ;
  Pointeur_Ai Premier_postordre (Pointeur_Ai *P) ;
  Pointeur_Ai Suivant_postordre (Pointeur_Ai *P) ;
  Pointeur_Ai Suivant_preordre (Pointeur_Ai *P) ;
  void Option1 (Pointeur_Ai *A1 , Pointeur_Ai *A2 , Pointeur_Ai *A3 , Pointeur_Ai *P , Pointeur_Ai *Q);
  void Option2 (Pointeur_Ai *A1 , Pointeur_Ai *A2 , Pointeur_Ai *A3 , Pointeur_Ai *P , Pointeur_Ai *Q);
  void Option3 (Pointeur_Ai *A1 , Pointeur_Ai *A2 , Pointeur_Ai *A3 , Pointeur_Ai *P , Pointeur_Ai *Q);
  void Option4 (Pointeur_Ai *A1 , Pointeur_Ai *A2 , Pointeur_Ai *A3 , Pointeur_Ai *P , Pointeur_Ai *Q);
  void Option5 (Pointeur_Ai *A1 , Pointeur_Ai *A2 , Pointeur_Ai *A3 , Pointeur_Ai *P , Pointeur_Ai *Q);
  int  Hauteur_max_arb (Pointeur_Ai P) ;
  int  Hauteur_min_arb (Pointeur_Ai P) ;
  float Moy_arb_gauche (Pointeur_Ai P , int N) ;
  float Moy_arb_droite (Pointeur_Ai P , int N) ;
  int Nb_noeud_niveaux(Pointeur_Ai root, int level);
  float Moy_arb(Pointeur_Ai root);
  void file_write1(FILE* f, Pointeur_Ai A3 , int N);
  void file_write2(FILE* f, Pointeur_Ai A3);

  /* ---------------------------------------------------- */
  /* ---------------------------------------------------- */
  /*               LES FONCTIONS ET ACTIONS               */
  /* ---------------------------------------------------- */
  /* ---------------------------------------------------- */
  /* ---------------------------------------------------- */
  /*             Fonction Creerarb_sansdouble             */
  /* ---------------------------------------------------- */
  bool  Creerarb_sansdouble (Pointeur_Ai *A , int *Nombre) 
    {
      /** Variables locales **/
      bool  Creerarb_sansdouble2 ;
      int I;
      int J;

      /** Corps du module **/
     I  =  0 ;
     *A  =  NULL ;
     while( I < *Nombre) {
       J  =  Aleanombre(32766) ;
       L  =  Inserer_sans_double ( & *A , & J ) ;
       if( L == True) {
         I  =  I + 1 ;
        
       } ;
      
     } ;
     if( *A != NULL) {
       Creerarb_sansdouble2  =  True ;
       }
     else
       {
       Creerarb_sansdouble2  =  False ;
      
     } ;
    
     return Creerarb_sansdouble2 ;
    }
  /* ---------------------------------------------------- */
  /*             Fonction Inserer_sans_double             */
  /* ---------------------------------------------------- */
  bool  Inserer_sans_double (Pointeur_Ai *A , int *Val) 
    {
      /** Variables locales **/
      bool  Inserer_sans_double2 ;
      Pointeur_Ai Parent=NULL;
      Pointeur_Ai Temp=NULL;

      /** Corps du module **/
     Inserer_sans_double2  =  True ;
     Parent  =  NULL ;
     Temp  =  *A ;
     while( Temp != NULL) {
       Parent  =  Temp ;
       if( *Val < Info_Ai ( Temp )) {
         Temp  =  Fg_Ai ( Temp ) ;
         }
       else
         {
         if( *Val > Info_Ai ( Temp )) {
           Temp  =  Fd_Ai ( Temp ) ;
           }
         else
           {
           Inserer_sans_double2  =  False ;
           Temp  =  NULL ;
          
         } ;
        
       } ;
      
     } ;
     if( Inserer_sans_double2 != False) {
       Creernoeud_Ai (& Temp ) ;
       Aff_info_Ai ( Temp , *Val ) ;
       if( Parent == NULL) {
         *A  =  Temp ;
         }
       else
         {
         if( *Val < Info_Ai ( Parent )) {
           Aff_fg_Ai ( Parent , Temp ) ;
           }
         else
           {
           Aff_fd_Ai ( Parent , Temp ) ;
          
         } ;
        
       } ;
       Aff_pere_Ai ( Temp , Parent ) ;
       Inserer_sans_double2  =  True ;
      
     } ;
    
     return Inserer_sans_double2 ;
    }
  /* ---------------------------------------------------- */
  /*                 Inserer_avec_double                  */
  /* ---------------------------------------------------- */
  void Inserer_avec_double (Pointeur_Ai *A , int *Val)
    {
      /** Variables locales **/
      Pointeur_Ai Parent=NULL;
      Pointeur_Ai Temp=NULL;

      /** Corps du module **/
     Parent  =  NULL ;
     Temp  =  *A ;
     while( Temp != NULL) {
       Parent  =  Temp ;
       if( *Val <= Info_Ai ( Temp )) {
         Temp  =  Fg_Ai ( Temp ) ;
         }
       else
         {
         Temp  =  Fd_Ai ( Temp ) ;
        
       } ;
      
     } ;
     Creernoeud_Ai (& Temp ) ;
     Aff_info_Ai ( Temp , *Val ) ;
     if( Parent == NULL) {
       *A  =  Temp ;
       }
     else
       {
       if( *Val <= Info_Ai ( Parent )) {
         Aff_fg_Ai ( Parent , Temp ) ;
         }
       else
         {
         Aff_fd_Ai ( Parent , Temp ) ;
        
       } ;
      
     } ;
     Aff_pere_Ai ( Temp , Parent ) ;
    
    }
  /* ---------------------------------------------------- */
  /*                     Verifier_bst                     */
  /* ---------------------------------------------------- */
  bool  Verifier_bst (Pointeur_Ai *A , int *Min_val , int *Max_val) 
    {
      /** Variables locales **/
      bool  Verifier_bst2 ;
      Pointeur_Ai _Px1=NULL;
      int _Px2;
      Pointeur_Ai _Px3=NULL;
      int _Px4;

      /** Corps du module **/
     if( *A == NULL) {
       Verifier_bst2  =  True ;
       }
     else
       {
       _Px1 =  Fg_Ai ( *A ) ;
       _Px2 =  Info_Ai ( *A ) ;
       _Px3 =  Fd_Ai ( *A ) ;
       _Px4 =  Info_Ai ( *A ) + 1 ;
       if( ( Info_Ai ( *A ) >= *Min_val ) && ( Info_Ai ( *A ) <= *Max_val ) && ( Verifier_bst ( &_Px1, & *Min_val , &_Px2) ) && ( Verifier_bst ( &_Px3, &_Px4, & *Max_val ) )) {
         ;
         Verifier_bst2  =  True ;
         }
       else
         {
         Verifier_bst2  =  False ;
        
       } ;
      
     } ;
    
     return Verifier_bst2 ;
    }
  /* ---------------------------------------------------- */
  /*                    Nombre_noeud                      */
  /* ---------------------------------------------------- */
  int  Nombre_noeud (Pointeur_Ai *P) 
    {
      /** Variables locales **/
      int  Nombre_noeud2 ;
      Pointeur_Ai _Px1=NULL;
      Pointeur_Ai _Px2=NULL;

      /** Corps du module **/
     if( *P == NULL) {
       Nombre_noeud2  =  0 ;
       }
     else
       {
       _Px1 =  Fg_Ai ( *P ) ;
       _Px2 =  Fd_Ai ( *P ) ;
       Nombre_noeud2  =  Nombre_noeud ( &_Px1) + Nombre_noeud ( &_Px2) + 1 ;
      
     } ;
    
     return Nombre_noeud2 ;
    }
  /* ---------------------------------------------------- */
  /*                    Verifier_fusion                   */
  /* ---------------------------------------------------- */
  bool  Verifier_fusion (Pointeur_Ai *P , int *N) 
    {
      /** Variables locales **/
      bool  Verifier_fusion2 ;
      int _Px1;
      int _Px2;

      /** Corps du module **/
     _Px1 =  0 ;
     _Px2 =  32766 ;
     if( ( Nombre_noeud ( & *P ) == *N ) && ( Verifier_bst ( & *P , &_Px1, &_Px2) == True )) {
       Verifier_fusion2  =  True ;
       }
     else
       {
       Verifier_fusion2  =  False ;
      
     } ;
    
     return Verifier_fusion2 ;
    }
  /* ---------------------------------------------------- */
  /*                    Supprimer_arb                     */
  /* ---------------------------------------------------- */
  void Supprimer_arb (Pointeur_Ai *P)
    {
      /** Variables locales **/
      Pointeur_Ai _Px1=NULL;
      Pointeur_Ai _Px2=NULL;

      /** Corps du module **/
     if( *P != NULL) {
       _Px1 =  Fg_Ai ( *P ) ;
       Supprimer_arb ( &_Px1) ;
       _Px2 =  Fd_Ai ( *P ) ;
       Supprimer_arb ( &_Px2) ;
       Liberernoeud_Ai ( *P ) ;
       *P  =  NULL ;
      
     } ;
    
    }
  /* ---------------------------------------------------- */
  /*                   Suivant_inordre                    */
  /* ---------------------------------------------------- */
  Pointeur_Ai Suivant_inordre (Pointeur_Ai *P) 
    {
      /** Variables locales **/
      Pointeur_Ai Suivant_inordre2 =NULL;
      bool L;

      /** Corps du module **/
     L  =  True ;
     if( Fd_Ai ( *P ) != NULL) {
       *P  =  Fd_Ai ( *P ) ;
       while( Fg_Ai ( *P ) != NULL) {
         *P  =  Fg_Ai ( *P ) ;
        
       } ;
       Suivant_inordre2  =  *P ;
       }
     else
       {
       while( ( Pere_Ai ( *P ) != NULL ) && ( L == True )) {
         if( Fg_Ai ( Pere_Ai ( *P ) ) == *P) {
           Suivant_inordre2  =  Pere_Ai ( *P ) ;
           L  =  False ;
          
         } ;
         if( L != False) {
           *P  =  Pere_Ai ( *P ) ;
          
         } ;
        
       } ;
       if( L != False) {
         Suivant_inordre2  =  NULL ;
        
       } ;
      
     } ;
    
     return Suivant_inordre2 ;
    }
  /* ---------------------------------------------------- */
  /*                  Premier_postordre                   */
  /* ---------------------------------------------------- */
  Pointeur_Ai Premier_postordre (Pointeur_Ai *P) 
    {
      /** Variables locales **/
      Pointeur_Ai Premier_postordre2 =NULL;

      /** Corps du module **/
     if( *P != NULL) {
       while( ( Fg_Ai ( *P ) == NULL ) && ( Fd_Ai ( *P ) != NULL )) {
         *P  =  Fd_Ai ( *P ) ;
        
       } ;
       while( Fg_Ai ( *P ) != NULL) {
         *P  =  Fg_Ai ( *P ) ;
         while( ( Fg_Ai ( *P ) == NULL ) && ( Fd_Ai ( *P ) != NULL )) {
           *P  =  Fd_Ai ( *P ) ;
          
         } ;
        
       } ;
      
     } ;
     Premier_postordre2  =  *P ;
    
     return Premier_postordre2 ;
    }
  /* ---------------------------------------------------- */
  /*                  Suivant_postordre                   */
  /* ---------------------------------------------------- */
  Pointeur_Ai Suivant_postordre (Pointeur_Ai *P) 
    {
      /** Variables locales **/
      Pointeur_Ai Suivant_postordre2 =NULL;
      bool L;
      Pointeur_Ai _Px1=NULL;

      /** Corps du module **/
     L  =  True ;
     if( ( Pere_Ai ( *P ) == NULL )) {
       Suivant_postordre2  =  NULL ;
       L  =  False ;
      
     } ;
     if( L == True) {
       ;
       if( ( *P == Fd_Ai ( Pere_Ai ( *P ) ) ) || ( Fd_Ai ( Pere_Ai ( *P ) ) == NULL )) {
         Suivant_postordre2  =  Pere_Ai ( *P ) ;
         }
       else
         {
         _Px1 =  Fd_Ai ( Pere_Ai ( *P ) ) ;
         Suivant_postordre2  =  Premier_postordre ( &_Px1) ;
        
       } ;
      
     } ;
    
     return Suivant_postordre2 ;
    }
  /* ---------------------------------------------------- */
  /*                  Suivant_preordre                    */
  /* ---------------------------------------------------- */
  Pointeur_Ai Suivant_preordre (Pointeur_Ai *P) 
    {
      /** Variables locales **/
      Pointeur_Ai Suivant_preordre2 =NULL;
      Pointeur_Ai Parent=NULL;
      bool L;

      /** Corps du module **/
     L  =  True ;
     if( Fg_Ai ( *P ) != NULL) {
       Suivant_preordre2  =  Fg_Ai ( *P ) ;
       }
     else
       {
       if( Fd_Ai ( *P ) != NULL) {
         Suivant_preordre2  =  Fd_Ai ( *P ) ;
         }
       else
         {
         Parent  =  Pere_Ai ( *P ) ;
         while( ( Parent != NULL ) && ( L == True )) {
           if( ( Fg_Ai ( Parent ) == *P ) && ( Fd_Ai ( Parent ) != NULL )) {
             Suivant_preordre2  =  Fd_Ai ( Parent ) ;
             L  =  False ;
             }
           else
             {
             *P  =  Parent ;
             Parent  =  Pere_Ai ( *P ) ;
            
           } ;
          
         } ;
         if( L == True) {
           Suivant_preordre2  =  NULL ;
          
         } ;
        
       } ;
      
     } ;
    
     return Suivant_preordre2 ;
    }
  /* ---------------------------------------------------- */
  /*                      Option1                         */
  /* ---------------------------------------------------- */
  void Option1 (Pointeur_Ai *A1 , Pointeur_Ai *A2 , Pointeur_Ai *A3 , Pointeur_Ai *P , Pointeur_Ai *Q)
    {
      /** Variables locales **/
      int _Px1;
      int _Px2;
      int _Px3;
      int _Px4;

      /** Corps du module **/
     *A3  =  NULL ;
    /* Initialisation des pointeurs */
     *P  =  *A1 ;
     *Q  =  *A2 ;
     while( Fg_Ai ( *P ) != NULL) {
       *P  =  Fg_Ai ( *P ) ;
      
     } ;
    /* Debut des parcours */
     while( ( *P != NULL ) && ( *Q != NULL )) {
       if( Min ( Info_Ai ( *P ) , Info_Ai ( *Q ) ) == Info_Ai ( *P )) {
         _Px1 =  Info_Ai ( *P ) ;
         Inserer_avec_double ( & *A3 , &_Px1) ;
         *P  =  Suivant_inordre ( & *P ) ;
         }
       else
         {
         _Px2 =  Info_Ai ( *Q ) ;
         Inserer_avec_double ( & *A3 , &_Px2) ;
         *Q  =  Suivant_preordre ( & *Q ) ;
        
       } ;
      
     } ;
     if( ( *P == NULL ) && ( *Q != NULL )) {
       while( *Q != NULL) {
         _Px3 =  Info_Ai ( *Q ) ;
         Inserer_avec_double ( & *A3 , &_Px3) ;
         *Q  =  Suivant_preordre ( & *Q ) ;
        
       } ;
      
     } ;
     if( ( *P != NULL ) && ( *Q == NULL )) {
       while( *P != NULL) {
         _Px4 =  Info_Ai ( *P ) ;
         Inserer_avec_double ( & *A3 , &_Px4) ;
         *P  =  Suivant_inordre ( & *P ) ;
        
       } ;
      
     } ;
    
    }
  /* ---------------------------------------------------- */
  /*                      Option2                         */
  /* ---------------------------------------------------- */
  void Option2 (Pointeur_Ai *A1 , Pointeur_Ai *A2 , Pointeur_Ai *A3 , Pointeur_Ai *P , Pointeur_Ai *Q)
    {
      /** Variables locales **/
      int _Px1;
      int _Px2;
      int _Px3;
      int _Px4;

      /** Corps du module **/
     *A3  =  NULL ;
    /* Initialisation des pointeurs */
     *P  =  *A1 ;
     *Q  =  *A2 ;
     while( Fg_Ai ( *P ) != NULL) {
       *P  =  Fg_Ai ( *P ) ;
      
     } ;
     *Q  =  Premier_postordre ( & *Q ) ;
    /* Debut des parcours */
     while( ( *P != NULL ) && ( *Q != NULL )) {
       if( Min ( Info_Ai ( *P ) , Info_Ai ( *Q ) ) == Info_Ai ( *P )) {
         _Px1 =  Info_Ai ( *P ) ;
         Inserer_avec_double ( & *A3 , &_Px1) ;
         *P  =  Suivant_inordre ( & *P ) ;
         }
       else
         {
         _Px2 =  Info_Ai ( *Q ) ;
         Inserer_avec_double ( & *A3 , &_Px2) ;
         *Q  =  Suivant_postordre ( & *Q ) ;
        
       } ;
      
     } ;
     if( ( *P == NULL ) && ( *Q != NULL )) {
       while( *Q != NULL) {
         _Px3 =  Info_Ai ( *Q ) ;
         Inserer_avec_double ( & *A3 , &_Px3) ;
         *Q  =  Suivant_postordre ( & *Q ) ;
        
       } ;
      
     } ;
     if( ( *P != NULL ) && ( *Q == NULL )) {
       while( *P != NULL) {
         _Px4 =  Info_Ai ( *P ) ;
         Inserer_avec_double ( & *A3 , &_Px4) ;
         *P  =  Suivant_inordre ( & *P ) ;
        
       } ;
      
     } ;
    
    }
  /* ---------------------------------------------------- */
  /*                      Option3                         */
  /* ---------------------------------------------------- */
  void Option3 (Pointeur_Ai *A1 , Pointeur_Ai *A2 , Pointeur_Ai *A3 , Pointeur_Ai *P , Pointeur_Ai *Q)
    {
      /** Variables locales **/
      int _Px1;
      int _Px2;
      int _Px3;
      int _Px4;

      /** Corps du module **/
     *A3  =  NULL ;
    /* Initialisation des pointeurs */
     *P  =  *A1 ;
     *Q  =  *A2 ;
    /* Debut des parcours */
     while( ( *P != NULL ) && ( *Q != NULL )) {
       if( Min ( Info_Ai ( *P ) , Info_Ai ( *Q ) ) == Info_Ai ( *P )) {
         _Px1 =  Info_Ai ( *P ) ;
         Inserer_avec_double ( & *A3 , &_Px1) ;
         *P  =  Suivant_preordre ( & *P ) ;
         }
       else
         {
         _Px2 =  Info_Ai ( *Q ) ;
         Inserer_avec_double ( & *A3 , &_Px2) ;
         *Q  =  Suivant_preordre ( & *Q ) ;
        
       } ;
      
     } ;
     if( ( *P == NULL ) && ( *Q != NULL )) {
       while( *Q != NULL) {
         _Px3 =  Info_Ai ( *Q ) ;
         Inserer_avec_double ( & *A3 , &_Px3) ;
         *Q  =  Suivant_preordre ( & *Q ) ;
        
       } ;
      
     } ;
     if( ( *P != NULL ) && ( *Q == NULL )) {
       while( *P != NULL) {
         _Px4 =  Info_Ai ( *P ) ;
         Inserer_avec_double ( & *A3 , &_Px4) ;
         *P  =  Suivant_preordre ( & *P ) ;
        
       } ;
      
     } ;
    
    }
  /* ---------------------------------------------------- */
  /*                      Option4                         */
  /* ---------------------------------------------------- */
  void Option4 (Pointeur_Ai *A1 , Pointeur_Ai *A2 , Pointeur_Ai *A3 , Pointeur_Ai *P , Pointeur_Ai *Q)
    {
      /** Variables locales **/
      int _Px1;
      int _Px2;
      int _Px3;
      int _Px4;

      /** Corps du module **/
     *A3  =  NULL ;
    /* Initialisation des pointeurs */
     *P  =  *A1 ;
     *Q  =  *A2 ;
     *P  =  Premier_postordre ( & *P ) ;
     *Q  =  Premier_postordre ( & *Q ) ;
    /* Debut des parcours */
     while( ( *P != NULL ) && ( *Q != NULL )) {
       if( Min ( Info_Ai ( *P ) , Info_Ai ( *Q ) ) == Info_Ai ( *P )) {
         _Px1 =  Info_Ai ( *P ) ;
         Inserer_avec_double ( & *A3 , &_Px1) ;
         *P  =  Suivant_postordre ( & *P ) ;
         }
       else
         {
         _Px2 =  Info_Ai ( *Q ) ;
         Inserer_avec_double ( & *A3 , &_Px2) ;
         *Q  =  Suivant_postordre ( & *Q ) ;
        
       } ;
      
     } ;
     if( ( *P == NULL ) && ( *Q != NULL )) {
       while( *Q != NULL) {
         _Px3 =  Info_Ai ( *Q ) ;
         Inserer_avec_double ( & *A3 , &_Px3) ;
         *Q  =  Suivant_postordre ( & *Q ) ;
        
       } ;
      
     } ;
     if( ( *P != NULL ) && ( *Q == NULL )) {
       while( *P != NULL) {
         _Px4 =  Info_Ai ( *P ) ;
         Inserer_avec_double ( & *A3 , &_Px4) ;
         *P  =  Suivant_postordre ( & *P ) ;
        
       } ;
      
     } ;
    
    }
  /* ---------------------------------------------------- */
  /*                      Option5                         */
  /* ---------------------------------------------------- */
  void Option5 (Pointeur_Ai *A1 , Pointeur_Ai *A2 , Pointeur_Ai *A3 , Pointeur_Ai *P , Pointeur_Ai *Q)
    {
      /** Variables locales **/
      int _Px1;
      int _Px2;
      int _Px3;
      int _Px4;

      /** Corps du module **/
     *A3  =  NULL ;
    /* Initialisation des pointeurs */
     *P  =  *A1 ;
     *Q  =  *A2 ;
     *Q  =  Premier_postordre ( & *Q ) ;
    /* Debut des parcours */
     while( ( *P != NULL ) && ( *Q != NULL )) {
       if( Min ( Info_Ai ( *P ) , Info_Ai ( *Q ) ) == Info_Ai ( *P )) {
         _Px1 =  Info_Ai ( *P ) ;
         Inserer_avec_double ( & *A3 , &_Px1) ;
         *P  =  Suivant_preordre ( & *P ) ;
         }
       else
         {
         _Px2 =  Info_Ai ( *Q ) ;
         Inserer_avec_double ( & *A3 , &_Px2) ;
         *Q  =  Suivant_postordre ( & *Q ) ;
        
       } ;
      
     } ;
     if( ( *P == NULL ) && ( *Q != NULL )) {
       while( *Q != NULL) {
         _Px3 =  Info_Ai ( *Q ) ;
         Inserer_avec_double ( & *A3 , &_Px3) ;
         *Q  =  Suivant_postordre ( & *Q ) ;
        
       } ;
      
     } ;
     if( ( *P != NULL ) && ( *Q == NULL )) {
       while( *P != NULL) {
         _Px4 =  Info_Ai ( *P ) ;
         Inserer_avec_double ( & *A3 , &_Px4) ;
         *P  =  Suivant_preordre ( & *P ) ;
        
       } ;
      
     } ;
    
    }
  /* ---------------------------------------------------- */
  /*                   Hauteur_max_arb                    */
  /* ---------------------------------------------------- */
  int  Hauteur_max_arb (Pointeur_Ai P) 
  {
    if( P == NULL) {
      return -1 ;
    }
    else
    {
      return Max ( Hauteur_max_arb ( Fg_Ai ( P ) ) , Hauteur_max_arb ( Fd_Ai ( P ) ) ) + 1 ;
    } ;
  }
  /* ---------------------------------------------------- */
  /*                   Hauteur_min_arb                    */
  /* ---------------------------------------------------- */
  int  Hauteur_min_arb (Pointeur_Ai P) 
  {
    if( P == NULL) {
      return -1 ;
    }
    else
    {
      return Min ( Hauteur_min_arb ( Fg_Ai ( P ) ) , Hauteur_min_arb ( Fd_Ai ( P ) ) ) + 1 ;
    } ;
  }
  /* ---------------------------------------------------- */
  /*                   Moy_arb_gauche                     */
  /* ---------------------------------------------------- */
  float Moy_arb_gauche (Pointeur_Ai P , int N)
  {
    P = Fg_Ai (P);
    return ((float) Nombre_noeud(&P) / (N - 1)) ;
  }
  /* ---------------------------------------------------- */
  /*                   Moy_arb_droite                     */
  /* ---------------------------------------------------- */
  float Moy_arb_droite (Pointeur_Ai P , int N)
  {
    P = Fd_Ai (P) ;
    return ((float) Nombre_noeud(&P) / (N - 1)) ;
  }
  /* ---------------------------------------------------- */
  /*                   Nb_noeud_niveaux                   */
  /* ---------------------------------------------------- */
  int Nb_noeud_niveaux(Pointeur_Ai root, int level) {
  if (root == NULL) {
    return 0;
  }

  if (level == 1) {
    return 1;
  } else if (level > 1) {
    return Nb_noeud_niveaux(root->Fg, level - 1) + Nb_noeud_niveaux(root->Fd, level - 1);
  }

  return 0;
  }
  /* ---------------------------------------------------- */
  /*                       Moy_arb                        */
  /* ---------------------------------------------------- */
  float Moy_arb(Pointeur_Ai root) {
  float sum = 0.0;
  int level ;
  int height = Hauteur_max_arb(root);

  for ( level = 1; level <= height + 1; level++) {
    int nodeCount = Nb_noeud_niveaux(root, level);
    sum += (float)nodeCount / pow(2, level - 1);
  }
  return sum/(height+1);
  }
  /* ---------------------------------------------------- */
  /*                      file_write                      */
  /* ---------------------------------------------------- */
  void file_write1(FILE* f, Pointeur_Ai A3 , int N)
  {
    float Nb1;
    int Nb2;
    // Moy_totale Moy_droite Moy_gauche Hateur_max Hauteur_min
    Nb1 = Moy_arb(A3);
    fprintf(f, "  %.2f",Nb1);
    Nb1 = Moy_arb_droite(A3 , 2*N);
    fprintf(f, "  %.2f",Nb1);
    Nb1 = Moy_arb_gauche(A3 , 2*N);
    fprintf(f, "  %.2f",Nb1);
    Nb2 = Hauteur_max_arb(A3);
    fprintf(f, "  %5d",Nb2);
    Nb2 = Hauteur_min_arb(A3);
    fprintf(f, "  %5d",Nb2);
  }

  void file_write2(FILE* f, Pointeur_Ai A3)
  {
    int Nb,h,i;
    h = Hauteur_max_arb(A3)+1;
    for (i = 1 ; i<=h;i++) {
      Nb = Nb_noeud_niveaux(A3, i);
      fprintf(f,"%5d  ",Nb);
    }
    fprintf(f,"\n");
  }



  int main(int argc, char *argv[])
    {
     srand(time(NULL));
     // Les fichiers de teste
        char file_name1[] = "info_globale.txt";
        char file_name2[] = "nb_par_niveau_1.txt";
        char file_name3[] = "nb_par_niveau_2.txt";
        char file_name4[] = "nb_par_niveau_3.txt";
        char file_name5[] = "nb_par_niveau_4.txt";
        char file_name6[] = "nb_par_niveau_5.txt";
        remove(file_name1);remove(file_name2);remove(file_name3);
        remove(file_name4);remove(file_name5);remove(file_name6);
        FILE *f1 = fopen(file_name1,"a");
        FILE *f2 = fopen(file_name2,"a");
        FILE *f3 = fopen(file_name3,"a");
        FILE *f4 = fopen(file_name4,"a");
        FILE *f5 = fopen(file_name5,"a");
        FILE *f6 = fopen(file_name6,"a");
      /*---------- NOTE ------------*/
      /* 
        On a mis les fonctions file_write en commentaire exprer pour
        ne pas ralentir l'execution
      */
     // La boucle pricipale
     M  =  50 ;
     N  =  10000 ;
    /* Generation des arbres aleatoires */
     for( I  =  1 ;I <=  M ; ++I){
       printf("Les arbre A1 et A2 numero : %d\n" , I );
       L  =  Creerarb_sansdouble ( & A1 , & N ) ;
       L  =  Creerarb_sansdouble ( & A2 , & N ) ;
      /* Fusion et teste 1 */
       Option1 ( & A1 , & A2 , & A3 , & P , & Q ) ;
       _Px1 =  2 * N ;
       printf ( "   Teste fusion 1 : %d\n", Verifier_fusion(&A3,&_Px1) ) ;
       //file_write1(f1,A3 ,N);
       //file_write2(f2,A3);
       Supprimer_arb ( & A3 ) ;
      /* Fusion et teste 2 */
       Option2 ( & A1 , & A2 , & A3 , & P , & Q ) ;
       _Px2 =  2 * N ;
       printf ( "   Teste fusion 2 : %d\n", Verifier_fusion(&A3,&_Px2) ) ;
       //file_write1(f1,A3 ,N);
       //file_write2(f3,A3);
       Supprimer_arb ( & A3 ) ;
      /* Fusion et teste 3 */
       Option3 ( & A1 , & A2 , & A3 , & P , & Q ) ;
       _Px3 =  2 * N ;
       printf ( "   Teste fusion 3 : %d\n", Verifier_fusion(&A3,&_Px3) ) ;
       //file_write1(f1,A3 ,N);
       //file_write2(f4,A3);
       Supprimer_arb ( & A3 ) ;
      /* Fusion et teste 4 */
       Option4 ( & A1 , & A2 , & A3 , & P , & Q ) ;
       _Px4 =  2 * N ;
       printf ( "   Teste fusion 4 : %d\n", Verifier_fusion(&A3,&_Px4) ) ;
       //file_write1(f1,A3 ,N);
       //file_write2(f5,A3);
       Supprimer_arb ( & A3 ) ;
      /* Fusion et teste 5 */
       Option5 ( & A1 , & A2 , & A3 , & P , & Q ) ;
       _Px5 =  2 * N ;
       printf ( "   Teste fusion 5 : %d\n", Verifier_fusion(&A3,&_Px5) ) ;
       //file_write1(f1,A3 ,N);
       //file_write2(f6,A3);
       Supprimer_arb ( & A3 ) ;
       Supprimer_arb ( & A1 ) ;
       Supprimer_arb ( & A2 ) ;
       // Retour de ligne a la fin de chaque iteration
       fprintf(f1,"\n");
     } ;
    
      fclose(f1);
      system("PAUSE");
      return 0;
    }