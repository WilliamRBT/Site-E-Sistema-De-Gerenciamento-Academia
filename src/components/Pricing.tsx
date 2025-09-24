import React from 'react';
import { Link } from 'react-router-dom'; // Importar Link

const PricingCard: React.FC<{plan: string; price: string; features: string[]; popular?: boolean;}> = ({ plan, price, features, popular = false }) => (
  <div className={`border ${popular ? 'border-orange-500 shadow-2xl shadow-orange-500/10' : 'border-gray-800'} bg-[#1a1a1a] p-8 rounded-xl flex flex-col transform transition-all duration-300 hover:border-orange-500 hover:scale-105 relative z-10`}>
    <h3 className="text-xl font-semibold text-orange-500 mb-4 text-center tracking-wider uppercase">{plan}</h3>
    <p className="text-5xl font-extrabold text-white mb-6 text-center">
      R${price}<span className="text-lg font-medium text-gray-400">/mês</span>
    </p>
    <ul className="space-y-4 text-gray-400 mb-8 flex-grow border-t border-gray-800 pt-8">
      {features.map((feature, index) => (
        <li key={index} className="flex items-start">
          <svg className="w-5 h-5 text-orange-500 mr-3 flex-shrink-0 mt-1" fill="none" stroke="currentColor" viewBox="0 0 24 24" xmlns="http://www.w3.org/2000/svg"><path strokeLinecap="round" strokeLinejoin="round" strokeWidth="2" d="M5 13l4 4L19 7"></path></svg>
          <span>{feature}</span>
        </li>
      ))}
    </ul>
    <Link to={`/planos/${plan.toLowerCase()}`} className={`mt-auto block w-full text-center py-3 px-6 rounded-md font-bold uppercase tracking-wider transition-colors duration-300 ${popular ? 'bg-orange-500 text-white hover:bg-orange-600' : 'bg-gray-800 text-gray-300 hover:bg-orange-500 hover:text-white'}`}>
      Escolher Plano
    </Link>
  </div>
);

const Pricing: React.FC = () => {
  const plans = [
    {
      plan: 'Básico',
      price: '99',
      features: ['Acesso 24/7 à área de musculação', 'Vestiários completos', 'Acompanhamento básico inicial']
    },
    {
      plan: 'Plus',
      price: '129',
      features: ['Todos os benefícios do Básico', 'Aulas Coletivas Ilimitadas', 'Acesso a todas as unidades', 'Avaliação Física Trimestral'],
      popular: true
    },
    {
      plan: 'Premium',
      price: '159',
      features: ['Todos os benefícios do Plus', 'Acompanhamento com Nutricionista', 'Acesso à área de spa e relaxamento', 'Traga um amigo 4x por mês']
    }
  ];

  return (
    <section id="planos" className="py-24 md:py-32 bg-[#181818]">
      <div className="container mx-auto px-6">
        <div className="text-center mb-16">
          <h2 className="text-4xl md:text-5xl font-black text-white">Nossos Planos</h2>
          <p className="text-lg text-gray-400 mt-4 max-w-2xl mx-auto font-light">Escolha o plano perfeito para seus objetivos. Sem taxas escondidas, sem complicações.</p>
        </div>
        <div className="grid grid-cols-1 md:grid-cols-3 gap-12 md:gap-8">
          {plans.map((p, index) => (
            <PricingCard key={index} {...p} />
          ))}
        </div>
      </div>
    </section>
  );
};

export default Pricing;